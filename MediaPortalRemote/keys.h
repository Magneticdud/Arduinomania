//keys to press on Transmission, and IR hex code on Receiving
//receiving codes from a random Panasonic Remote

/*const int leftclickR = 0;
const int leftclickT = 0;
const int rightclickR = 0;
const int rightclickT = 0;*/
const int windowskeyR = 0x1EEB72DE;
const int windowskeyT = KEY_LEFT_GUI;
//send ctrl+d to make the auto3d menu appear
const int auto3dswitchR = 0xE52D8932;
const int auto3dswitchT = 'd';
const int leftarrowR = 0xA5DB7F00;
const int leftarrowT = KEY_LEFT_ARROW;
const int rightarrowR = 0x4296B834;
const int rightarrowT = KEY_RIGHT_ARROW;
const int uparrowR = 0x25ADDEF8;
const int uparrowT = KEY_UP_ARROW;
const int downarrowR = 0xC1B35862;
const int downarrowT = KEY_DOWN_ARROW;
//home is H on mediaportal dont need it
//const int homeR = 0;
//const char homeT = 'h';  //i think it could be also int, anyways it's stored as 0x68
const int enterR = 0xD929863E;
const int enterT = KEY_RETURN;
//pause is spacebar on mediaportal
const int pauseR = 0x25ADDEE8; //also play //wrong code
const int pauseT = KEY_BACKSPACE;
//first item is home key
const int firstR = 0;
const int firstT = KEY_HOME;
//last item is end key
const int lastR = 0;
const int lastT = KEY_END;
//pgup is previous page
const int previouspageR = 0xFFFFFFFF;
const int previouspageT = KEY_PAGE_UP;
//pgdown is next page
const int nextpageR = 0xDBDD58A8;
const int nextpageT = KEY_PAGE_DOWN;
//M is mute, don't need
//const int muteR = 0;
//const int muteT = 0;
//P is play all
const int playallR = 0;
const char playallT = 'p';
//B is stop
const int stopR = 0xE929863E; //wrong code
const char stopT = 'b';
//F3 is show info
const int showinfoR = 0xDD81310E;
const int showinfoT = KEY_F3;
//F5 is rewind
const int rewindR = 0x333725A;
const int rewindT = KEY_F5;
//F6 is Fast forward
const int ffR = 0xE0B4A864;
const int ffT = KEY_F6;
//F7 is Play previous and switch channel
const int playpreviousR = 0xF0211C96;
const int playpreviousT = KEY_F7;
//F8 is Play next and switch channel
const int playnextR = 0x1FEC4C3C;
const int playnextT = KEY_F8;
//F9 is show context menu
const int showcontextR = 0x2389FD1B;
const int showcontextT = KEY_F9;
const int ESCR = 0x3D240CD4;
const int ESCT = KEY_ESC;
const int ALTF4R = 0;
const int ALTF4T = 0;
// U is go to Parent folder
const int parentfolderR = 0;
const char parentfolderT = 'u';
// X Switch between MediaPortal GUI and the currently playing media, such as fullscreen tv, video, visualization or Now Playing
const int PIPR = 0x1D4F0764;
const char PIPT = 'x';
// R records
const int recR = 0x5457692E;
const char recT = 'r';
const int key1R = 0xBA495DFC;
const char key1T = '1';
const int key2R = 0xED039CDE;
const char key2T = '2';
const int key3R = 0xDC8D6CD2;
const char key3T = '3';
const int key4R = 0x72A84008;
const char key4T = '4';
const int key5R = 0x9BC76C0;
const char key5T = '5';
const int key6R = 0x8F528812;
const char key6T = '6';
const int key7R = 0xC9FE570E;
const char key7T = '7';
const int key8R = 0x40325FCC;
const char key8T = '8';
const int key9R = 0x9A7316D8;
const char key9T = '9';
//0 is also used to delete recordings and the last channel, consider adding a duplicate key?
const int key0R = 0x247E57FA;
const char key0T = '0';
//Y is show/hide OSD
const int osdshowR = 0;
const char osdshowT = 'y';
//F1 reset to default
//const int defaultR = 0;
//const int defaultT = KEY_F1;
const int redR = 0xDFDACAC5;
const char redT = 'q';
const int greenR = 0x8406E731;
const char greenT = 'w';
const int yellowR = 0x1451B3;
const char yellowT = 'o';
const int blueR = 0xEC2A5E1B;
const char blueT = 'p';
const int audioR = 0x56623548;
const char audioT = 'a';
const int subsR = 0xB84BC113;
const char subsT = 'l';
const int zoomR = 0x136B9A5C;
const char zoomT = 's';
