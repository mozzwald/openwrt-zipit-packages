#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <inttypes.h>

struct uinput_user_dev   uinp;
struct input_event     event;

int ufile, retcode, i, me, alt, alt2, counter;

int accel = 1;
uint32_t accel_count = 0;
int accel_base = 3;

int send_event(int ufile, __u16 type, __u16 code, __s32 value)
{
    struct input_event event;

    memset(&event, 0, sizeof(event));
    event.type = type;
    event.code = code;
    event.value = value;

    if (write(ufile, &event, sizeof(event)) != sizeof(event)) {
        fprintf(stderr, "Error sending Event");
        return -1;
    }

return 0;
}

void check_hold(int jx, int jy) {
    if (jx == 0 && jy == 0) {
        accel_count = 0;
    } else {
        accel_count++;
    }

    accel = 1 + accel_count / 8;
}

void processEvent(struct input_event evt) {
    static int jx, jy;
    int moving = 0;

#if 0
    printf("%d ",evt.type);
    printf("%d ",evt.code);
    printf("%d \n",evt.value);
#endif  
  
    //option
    if(evt.code == 357) {
        if(evt.value == 1 /*|| evt.value == 2*/) { 
            if(alt == 1) {
                //printf("toggled off\n");
                alt = 0 ;
            } else if(alt == 0) {
                //	printf("toggled on\n");
                alt = 1 ;	
            }
        }
    }

    if(alt == 1) {
        switch(evt.code) {
			case 103: 
			//up
            moving = 1;
            jy = evt.value == 0 ? 0 : -accel_base;
            check_hold(jx, jy);
		   	break;
		   	
		   	case 108:
			//down
            moving = 1;
            jy = evt.value == 0 ? 0 : accel_base;
            check_hold(jx, jy);
		    break;
	
		   	case 105:
			//left
            moving = 1;
            jx = evt.value == 0 ? 0 : -accel_base;
            check_hold(jx, jy);
		    break;
			
			case 106:
			//right
            moving = 1;
            jx = evt.value == 0 ? 0 : accel_base;
            check_hold(jx, jy);
            break;
          		
   			case 107:
			//	left mouse
  	        send_event(ufile, EV_KEY, BTN_RIGHT, evt.value);
  	        break;
			
			case 166:
            //right mouse
            send_event(ufile, EV_KEY, BTN_LEFT, evt.value);
            break;
			
	        case 200:
            //middle  mouse
            send_event(ufile, EV_KEY, BTN_MIDDLE, evt.value);
            break;

		case 104:
	    //F1
	    send_event(ufile, EV_KEY, KEY_F1, evt.value);
	    break;
	        case 109:
	    //F5
	    send_event(ufile, EV_KEY, KEY_F5, evt.value);
	    break;
 		default:
    	    send_event(ufile, EV_KEY,evt.code, evt.value);
			break; 	
  		}

        if (moving) {
			send_event(ufile, EV_REL, REL_Y, jy*accel); 
			send_event(ufile, EV_REL, REL_X, jx*accel); 
        }
  		
  		//the sync crap
  		send_event(ufile, EV_SYN, SYN_REPORT, 0);
    } else {
        send_event(ufile, EV_KEY,evt.code, evt.value);
        send_event(ufile, EV_SYN, SYN_REPORT, 0);
    }
			 
    //printf("outside\n");
}




int main(void) {
    int evdev = -1;

    ufile = open("/dev/input/uinput", O_WRONLY);
    if (ufile == 0) {
        printf("Could not open uinput.\n");
        exit(1);
    }

    memset(&uinp, 0, sizeof(uinp));
    strncpy(uinp.name, "Zipit2 Mouse Emulator", sizeof(uinp.name)-1);
    uinp.id.version = 4;
    uinp.id.bustype = BUS_USB;

    ioctl(ufile, UI_SET_EVBIT, EV_KEY);
    ioctl(ufile, UI_SET_EVBIT, EV_REL);
    ioctl(ufile, UI_SET_RELBIT, REL_X);
    ioctl(ufile, UI_SET_RELBIT, REL_Y);

    for (i=0; i<256; i++) {
        ioctl(ufile, UI_SET_KEYBIT, i);
    }

    ioctl(ufile, UI_SET_KEYBIT, BTN_MOUSE);
    ioctl(ufile, UI_SET_KEYBIT, BTN_LEFT);
    ioctl(ufile, UI_SET_KEYBIT, BTN_RIGHT);
    ioctl(ufile, UI_SET_KEYBIT, BTN_MIDDLE);	

    retcode = write(ufile,&uinp, sizeof(uinp));

    if (ioctl(ufile,UI_DEV_CREATE) < 0) {  
        fprintf(stderr, "Error creating Device\n");
        exit(1);
    }

    evdev = open("/dev/input/event1", O_RDONLY);
    int value = 1;
    ioctl(evdev, EVIOCGRAB, &value);
    struct input_event ev[64];	
	
    for (;;) {
        me=read(evdev,ev,sizeof(struct input_event)*64);
    	for (counter = 0;
            counter < (int) (me / sizeof(struct input_event));
            counter++) {
            if (EV_KEY == ev[counter].type) {
                processEvent(ev[counter]);
            }
        }
    }

    // destroy the device
    ioctl(ufile, UI_DEV_DESTROY);
    close(ufile);
}
