#include<iostream>
#include<string>
#include<fstream>



using namespace std;
//pet class begin//
class Pet{
  public:
    Pet();
    Pet(int h,int e,int ms,string emot);
    virtual void Feed(int option)=0;//
    int getHunger(){
      return hunger;
    }



    virtual void Play(int option)=0;//
    int getEnergy(){
      return energy;
    }



    int getMentalState(){
      return mentalState;
    }

    void setName(string n){
      name=n;
    }

    string getName(){
      return name;
    }
    virtual void sleep()=0;
    string getEmotion(){
      return emotion;
    }

    bool checkDeath(){
      if(hunger<=0){
        cout<<getName()<<"'s hunger reached zero"<<endl;
        return false;
      }
      if(energy<=0){
        cout<<getName()<<"'s energy reached zero"<<endl;
        return false;
      }
      if(mentalState<=0){
        cout<<getName()<<"'s Mental State reached zero"<<endl;
        return false;
      }
      return true;

    }
    void setEmotion(){
      if((mentalState>=12)&&(mentalState<=20)){
        emotion="happy";
      }
      else if((mentalState>=6)&&(mentalState<=11)){
        emotion="neutral";
      }
      else if((mentalState>=1)&&(mentalState<=5)){
        emotion="sad";
      }
    }

  protected:
    int hunger;
    int energy;
    int mentalState;
    string emotion;

  private:
    string name;


};
Pet::Pet(){
  hunger=20;
  energy=20;
  mentalState=20;
  emotion="happy";
}
Pet::Pet(int h,int e,int ms,string emot){
  hunger=h;
  energy=e;
  mentalState=ms;
  emotion=emot;
}
//pet class end//

//dog class begin//
class Dog:public Pet{
  public:
    Dog():Pet(){

    }

    bool playMenu(){
      if((energy>=1)&&(hunger>=1)){
        cout<<"How do you want to play with "<<getName()<<endl;
        cout<<"1.Run with "<<getName()<<"(energy-7,mental state+2,hunger-4)"<<endl;
        cout<<"2.Play Fetch"<<"(energy-5,mental state+2,hunger-4)"<<endl;
        cout<<"3.Tug of War"<<"(energy-3,mental state+4,hunger-3)"<<endl;
        cout<<"choose option(1,2,or 3):"<<endl;
        return true;
      }
      else{
        cout<<"Not enough energy to play right now..."<<endl;
        cout<<endl;
        return false;
      }
    }


    void Play(int option){
      if(option== 1){
        cout<<"Running with "<<getName()<<"...."<<endl;
        cout<<endl;
        energy-=7;
        mentalState+=2;
        hunger-=4;
        if(mentalState>20){
          mentalState=20;
        }


      }
      else if(option==2){
        cout<<"Playing Fetch with "<<getName()<<"...."<<endl;
        cout<<endl;
        energy-=5;
        mentalState+=2;
        hunger-=4;
        if(mentalState>20){
          mentalState=20;
        }

      }
      else if(option==3){
        cout<<"Tugging of war with "<<getName()<<"...."<<endl;
        cout<<endl;
        energy-=3;
        mentalState+=4;
        hunger-=3;
        if(mentalState>20){
          mentalState=20;
        }

      }
      else{
        cout<<"Invalid option please try again."<<endl;


      }




    }

    Dog(int hu,int en,int ms,string empl){
      hunger=hu;
      energy=en;
      mentalState=ms;
      emotion=empl;

    }
    void Dfoodmenu(){

      cout<<"What would you like to feed "<<getName()<<endl;
      cout<<"1.Steak(hunger+5,energy-4,mental state-3)"<<endl;
      cout<<"2.Kibble(hunger+4,energy+3)"<<endl;
      cout<<"3.Small treat(hunger+2,energy+1,mental state+4)"<<endl;
      cout<<"Choose Option(1, 2, or 3):";



    }

    void Feed(int option){
      if(option==1){
        cout<<getName()<<" is eating Steak"<<endl;
        cout<<endl;
        hunger+=5;
        energy-=4;
        mentalState -=3;
        if(hunger>=20){
          hunger=20;
        }

      }
      else if(option==2){
        cout<<getName()<<" is eating kibble"<<endl;
        cout<<endl;
        hunger+=4;
        energy+=3;
        if(hunger>=20){
          hunger=20;
        }
        if(energy>=20){
          energy=20;
        }
      }
      else if(option ==3){
        cout<<getName()<<" is eating a small treat"<<endl;
        cout<<endl;
        hunger+=2;
        energy+=1;
        mentalState+=4;

        if(hunger>=20){
          hunger=20;
        }
        if(energy>=20){
          energy=20;
        }
        if(mentalState>=20){
          mentalState=20;
        }
      }
      else{
        cout<<"Invalid option, please try again"<<endl;
      }

    }
    void sleep(){
      cout<<getName()<<" is asleep..."<<endl;
      mentalState=20;
      energy=20;
      hunger-=6;

    }
    void dogPrint(){
      cout<<"     __"<<endl;
      cout<<"(___()'`;"<<endl;
      cout<<"/,    /`"<<endl;
      cout<<"\\\\"<<"""---\\\\"<<endl;
      cout<<endl;
    }
    string petType(){
      return "Dog";
    }




};




//dog class end//



//snake class begin//
class Snake:public Pet{
  public:
    Snake():Pet(){

    }

    bool playMenu(){
      if((energy>=1)&&(hunger>=1)){
        cout<<"How do you want to play with "<<getName()<<endl;
        cout<<"1.Slither with "<<getName()<<"(energy-6,mental state+4,hunger-2)"<<endl;
        cout<<"2.Play hide and seek with "<<getName()<<"(energy-2,mental state+5,hunger-2)"<<endl;
        cout<<"3.Take "<<getName()<<" for a swim"<<"(energy-7,mental state+4,hunger-3)"<<endl;
        cout<<"choose option(1,2,or 3):"<<endl;
        return true;
      }
      else{
        cout<<"Not enough energy to play right now..."<<endl;
        cout<<endl;
        return false;
      }
    }


    void Play(int option){
      if(option== 1){
        cout<<"Slitering with "<<getName()<<"...."<<endl;
        cout<<endl;
        energy-=6;
        mentalState+=4;
        hunger-=2;
        if(mentalState>20){
          mentalState=20;
        }


      }
      else if(option==2){
        cout<<"Playing hide and seek with "<<getName()<<"...."<<endl;
        cout<<endl;
        energy-=2;
        mentalState+=5;
        hunger-=2;
        if(mentalState>20){
          mentalState=20;
        }

      }
      else if(option==3){
        cout<<"Swimming with "<<getName()<<"...."<<endl;
        cout<<endl;
        energy-=7;
        mentalState+=4;
        hunger-=3;
        if(mentalState>20){
          mentalState=20;
        }

      }
      else{
        cout<<"Invalid option please try again."<<endl;


      }




    }

    Snake(int hu,int en,int ms,string empl){
      hunger=hu;
      energy=en;
      mentalState=ms;
      emotion=empl;

    }
    void Sfoodmenu(){

      cout<<"What would you like to feed "<<getName()<<endl;
      cout<<"1.Mouse(hunger+9,energy-4,mental state-3)"<<endl;
      cout<<"2.Small frog(hunger+8,energy+3)"<<endl;
      cout<<"3.Small lizard(hunger+7,energy+1,mental state+4)"<<endl;
      cout<<"Choose Option(1, 2, or 3):";



    }

    void Feed(int option){
      if(option==1){
        cout<<getName()<<" is eating a mouse"<<endl;
        cout<<endl;
        hunger+=9;
        energy-=4;
        mentalState -=3;
        if(hunger>=20){
          hunger=20;
        }

      }
      else if(option==2){
        cout<<getName()<<" is eating a small frog"<<endl;
        cout<<endl;
        hunger+=8;
        energy+=3;
        if(hunger>=20){
          hunger=20;
        }
        if(energy>=20){
          energy=20;
        }
      }
      else if(option ==3){
        cout<<getName()<<" is eating a small lizard"<<endl;
        cout<<endl;
        hunger+=7;
        energy+=1;
        mentalState+=4;

        if(hunger>=20){
          hunger=20;
        }
        if(energy>=20){
          energy=20;
        }
        if(mentalState>=20){
          mentalState=20;
        }
      }

    }
    void sleep(){
      cout<<getName()<<" is asleep..."<<endl;
      mentalState=20;
      energy=20;
      hunger-=7;

    }
    void snakePrint(){
      cout<<"             ____"<<endl;
      cout<<"            / . .\\\
      "<<endl;
      cout<<"            \\  ---<"<<endl;
      cout<<"             \\  /"<<endl;
      cout<<"   __________/ /"<<endl;
      cout<<"-=:___________/"<<endl;
      cout<<endl;
    }
    string petType(){
      return "Snake";
    }


};


//snake class end//




//parrot class begin//
class Parrot:public Pet{
public:
  Parrot():Pet(){

  }

  bool playMenu(){
    if((energy>=1)&&(hunger>=1)){
      cout<<"How do you want to play with "<<getName()<<endl;
      cout<<"1.Fly with "<<getName()<<"(energy-5,mental state+1,hunger-3)"<<endl;
      cout<<"2.Dance with "<<getName()<<"(energy-7,mental state+4,hunger-4)"<<endl;
      cout<<"3.Talk to "<<getName()<<"(energy-2,mental state+7,hunger-2)"<<endl;
      cout<<"choose option(1,2,or 3):"<<endl;
      return true;
    }
    else{
      cout<<"Not enough energy to play right now..."<<endl;
      cout<<endl;
      return false;
    }
  }


  void Play(int option){
    if(option== 1){
      cout<<"Flying with "<<getName()<<"...."<<endl;
      cout<<endl;
      energy-=5;
      mentalState+=1;
      hunger-=3;
      if(mentalState>20){
        mentalState=20;
      }


    }
    else if(option==2){
      cout<<"Dancing with "<<getName()<<"...."<<endl;
      cout<<endl;
      energy-=7;
      mentalState+=4;
      hunger-=4;
      if(mentalState>20){
        mentalState=20;
      }

    }
    else if(option==3){
      cout<<"Talking with "<<getName()<<"...."<<endl;
      cout<<endl;
      energy-=2;
      mentalState+=7;
      hunger-=2;
      if(mentalState>20){
        mentalState=20;
      }

    }
    else{
      cout<<"Invalid option please try again."<<endl;


    }




  }

  Parrot(int hu,int en,int ms,string empl){
    hunger=hu;
    energy=en;
    mentalState=ms;
    emotion=empl;

  }
  void Pfoodmenu(){

    cout<<"What would you like to feed "<<getName()<<endl;
    cout<<"1.Seeds(hunger+3.energy-1,mental state+2)"<<endl;
    cout<<"2.Fresh fruit(hunger+5,energy+4,mental state+3)"<<endl;
    cout<<"3.Fresh vegetables(hunger+5,energy+4,mental state+2)"<<endl;
    cout<<"Choose Option(1, 2, or 3):";



  }

  void Feed(int option){
    if(option==1){
      cout<<getName()<<" is eating seeds"<<endl;
      cout<<endl;
      hunger+=3;
      energy-=1;
      mentalState+=2;
      if(hunger>=20){
        hunger=20;
      }
      if(mentalState>=20){
        mentalState=20;
      }

    }
    else if(option==2){
      cout<<getName()<<" is eating fresh fruit"<<endl;
      cout<<endl;
      hunger+=5;
      energy+=4;
      mentalState+=3;
      if(hunger>=20){
        hunger=20;
      }
      if(energy>=20){
        energy=20;
      }
      if(mentalState>=20){
        mentalState=20;
      }
    }
    else if(option ==3){
      cout<<getName()<<" is eating fresh vegetables"<<endl;
      cout<<endl;
      hunger+=5;
      energy+=4;
      mentalState+=2;

      if(hunger>=20){
        hunger=20;
      }
      if(energy>=20){
        energy=20;
      }
      if(mentalState>=20){
        mentalState=20;
      }
    }

  }
  void sleep(){
    cout<<getName()<<" is asleep..."<<endl;
    mentalState=20;
    energy=20;
    hunger-=5;

  }
  void parrotPrint(){
    cout<<"  \\\\"<<endl;
    cout<<"  (o>"<<endl;
    cout<<"  //\\"<<endl;
    cout<<"__V_/_____"<<endl;
    cout<<"  ||"<<endl;
    cout<<"  ||"<<endl;
    cout<<endl;
  }

  string petType(){
    return "Parrot";
  }

};




//parrot class end//





















//ALL FUNCTIONS//
void mainMenu(){
  cout<<"TAMAGOTCHI PET GAME"<<endl;
  cout<<endl;
  cout<<"1-New Pet"<<endl;
  cout<<"2-Load Pet"<<endl;
  cout<<"e-Exit"<<endl;
}
void petSelectionMenu(){
  cout<<"ALL PET OPTIONS"<<endl;
  cout<<"1.Dog(Extremly energetic and playful but gets hungry very easily, will listen to you wholeheartedly even if it kills him)"<<endl;
  cout<<"2.Snake(Very timid and shy and also so slightly venomous, one big meal a day can keep it satisfied, may bite you if it gets sad)"<<endl;
  cout<<"3.Parrot(Extremly twitchy and slighty annoying, also there is a chance that it will fly away if not treated well)"<<endl;
  cout<<"Choose Your Pet!!!!"<<endl;
  cout<<"RULES:Keep your pet alive or with you for as long as possible, there is no winning just keep your pet fed and energized at all times"<<endl;
  cout<<"There are four attributes to a pet, hunger, mental state, energy, and emotion. Each attribute is at max 20 points, and the higher the value the better."<<endl;
  cout<<"emotion and mental state are tied together and the pet's emotion will be based on its mental state: if the mental state= 1-5, then the pet is sad."<<endl;
  cout<<"If the mental state = 6-11, then the pet is neutral. If the mental state=11-20, then the pet is happy."<<endl;
  cout<<"Also if any of the attributes reach zero then depending on the pet, the pet will either die, bite you, or fly away. If this happens it is GAME OVER and you will have to start a new game."<<endl;
  cout<<"Select Option(1,2,or 3):";


}
template<typename type>
void actionMenu(type obj){
  cout<<"------------------------------------"<<endl;
  cout<<"What would you like to do with "<<obj.getName()<<endl;
  cout<<"1.Play with "<<obj.getName()<<endl;
  cout<<"2.Feed "<<obj.getName()<<endl;
  cout<<"3.Put "<<obj.getName()<<" to bed"<<"(Will max mental state and energy to 20 and will lower hunger)"<<endl;
  cout<<"q.Save and quit game"<<endl;
  cout<<"Enter option(1,2,3,or q):"<<endl;
  cout<<"------------------------------------"<<endl;


}



int main(){
  string option;






  while(option !="e"){
    mainMenu();
    cin>>option;
    if(option=="1"){
      petSelectionMenu();
      int op;
      cin>>op;
      if(op==1){
        Dog dog;
        cout<<"What would you like to name your Dog?"<<endl;
        string name;
        cin>>name;
        dog.setName(name);
        cout<<"Here is "<<dog.getName()<<endl;

        string selection;
        while(selection != "q"){
          dog.dogPrint();
          cout<<"Energy:"<<dog.getEnergy()<<endl;
          cout<<"Mental State:"<<dog.getMentalState()<<endl;
          cout<<"Hunger:"<<dog.getHunger()<<endl;
          cout<<dog.getName()<<" is currently feeling "<<dog.getEmotion()<<endl;
          cout<<endl;
          actionMenu(dog);
          cin>>selection;

          cout<<endl;
          cout<<endl;
          if(selection =="1"){
            if(dog.playMenu()==false){

            }
            else{
              int pa;
              cin>>pa;
              dog.Play(pa);
              dog.setEmotion();
              if(dog.checkDeath()==false){
                cout<<dog.getName()<<" has died..."<<endl;
                cout<<"GAME OVER"<<endl;
                break;
              }
            }
          }
          else if(selection=="2"){
            dog.Dfoodmenu();
            int o;
            cin>>o;
            dog.Feed(o);
            dog.setEmotion();
            if(dog.checkDeath()==false){
              cout<<dog.getName()<<" has died..."<<endl;
              cout<<"GAME OVER"<<endl;
              break;
            }



          }
          else if(selection=="3"){
            dog.sleep();
            cout<<"enter in anything to wake "<<dog.getName()<<" up"<<endl;
            string wake;
            cin>>wake;
            if(dog.checkDeath()==false){
              cout<<dog.getName()<<" has died..."<<endl;
              cout<<"GAME OVER"<<endl;
              break;
            }

          }
          if(selection=="q"){
            //file save
            cout<<"Saving progress..."<<endl;
            ofstream ofile;
            ofile.open("savedgame.txt");
            ofile<<dog.petType()<<endl;
            ofile<<dog.getName()<<endl;
            ofile<<dog.getEnergy()<<endl;
            ofile<<dog.getMentalState()<<endl;
            ofile<<dog.getHunger()<<endl;
            ofile<<dog.getEmotion()<<endl;
            cout<<"PROGRESS SAVED!!!"<<endl;
            cout<<endl;
          }

        }




      }
      else if(op==2){
        Snake snake;
        cout<<"What would you like to name your Snake?"<<endl;
        string name;
        cin>>name;
        snake.setName(name);
        cout<<"Here is "<<snake.getName()<<endl;

        string selection;
        while(selection != "q"){
          snake.snakePrint();
          cout<<"Energy:"<<snake.getEnergy()<<endl;
          cout<<"Mental State:"<<snake.getMentalState()<<endl;
          cout<<"Hunger:"<<snake.getHunger()<<endl;
          cout<<snake.getName()<<" is currently feeling "<<snake.getEmotion()<<endl;
          cout<<endl;
          actionMenu(snake);
          cin>>selection;

          cout<<endl;
          cout<<endl;
          if(selection =="1"){
            if(snake.playMenu()==false){

            }
            else{
              int pa;
              cin>>pa;
              snake.Play(pa);
              snake.setEmotion();
              if(snake.checkDeath()==false){
                cout<<snake.getName()<<" bit you..."<<endl;
                cout<<"GAME OVER"<<endl;
                break;
              }
            }
          }
          else if(selection=="2"){
            snake.Sfoodmenu();
            int o;
            cin>>o;
            snake.Feed(o);
            snake.setEmotion();
            if(snake.checkDeath()==false){
              cout<<snake.getName()<<" bit you..."<<endl;
              cout<<"GAME OVER"<<endl;
              break;
            }



          }
          else if(selection=="3"){
            snake.sleep();
            cout<<"enter in anything to wake "<<snake.getName()<<" up"<<endl;
            string wake;
            cin>>wake;
            if(snake.checkDeath()==false){
              cout<<snake.getName()<<" bit you..."<<endl;
              cout<<"GAME OVER"<<endl;
              break;
            }

          }
          if(selection=="q"){
            //file save
            cout<<"Saving progress..."<<endl;
            ofstream ofile;
            ofile.open("savedgame.txt");
            ofile<<snake.petType()<<endl;
            ofile<<snake.getName()<<endl;
            ofile<<snake.getEnergy()<<endl;
            ofile<<snake.getMentalState()<<endl;
            ofile<<snake.getHunger()<<endl;
            ofile<<snake.getEmotion()<<endl;
            cout<<"PROGRESS SAVED!!!"<<endl;
            cout<<endl;
          }

        }


      }

      else if(op==3){
        Parrot parrot;
        cout<<"What would you like to name your parrot?"<<endl;
        string name;
        cin>>name;
        parrot.setName(name);
        cout<<"Here is "<<parrot.getName()<<endl;

        string selection;
        while(selection != "q"){
          parrot.parrotPrint();
          cout<<"Energy:"<<parrot.getEnergy()<<endl;
          cout<<"Mental State:"<<parrot.getMentalState()<<endl;
          cout<<"Hunger:"<<parrot.getHunger()<<endl;
          cout<<parrot.getName()<<" is currently feeling "<<parrot.getEmotion()<<endl;
          cout<<endl;
          actionMenu(parrot);
          cin>>selection;

          cout<<endl;
          cout<<endl;
          if(selection =="1"){
            if(parrot.playMenu()==false){

            }
            else{
              int pa;
              cin>>pa;
              parrot.Play(pa);
              parrot.setEmotion();
              if(parrot.checkDeath()==false){
                cout<<parrot.getName()<<" flew away..."<<endl;
                cout<<"GAME OVER"<<endl;
                break;
              }
            }
          }
          else if(selection=="2"){
            parrot.Pfoodmenu();
            int o;
            cin>>o;
            parrot.Feed(o);
            parrot.setEmotion();
            if(parrot.checkDeath()==false){
              cout<<parrot.getName()<<" flew away..."<<endl;
              cout<<"GAME OVER"<<endl;
              break;
            }



          }
          else if(selection=="3"){
            parrot.sleep();
            cout<<"enter in anything to wake "<<parrot.getName()<<" up"<<endl;
            string wake;
            cin>>wake;
            if(parrot.checkDeath()==false){
              cout<<parrot.getName()<<" flew away..."<<endl;
              cout<<"GAME OVER"<<endl;
              break;
            }

          }
          if(selection=="q"){
            //file save
            cout<<"Saving progress..."<<endl;
            ofstream ofile;
            ofile.open("savedgame.txt");
            ofile<<parrot.petType()<<endl;
            ofile<<parrot.getName()<<endl;
            ofile<<parrot.getEnergy()<<endl;
            ofile<<parrot.getMentalState()<<endl;
            ofile<<parrot.getHunger()<<endl;
            ofile<<parrot.getEmotion()<<endl;
            cout<<"PROGRESS SAVED!!!"<<endl;
            cout<<endl;

          }

        }

      }


    }



    else if(option=="2"){
      ifstream file;
      bool var=true;
      while(var){
        cout<<"What is the save file's name?"<<endl;
        string filename;
        cin>>filename;
        file.open(filename);
        if(!file.is_open()){
          cout<<"File not found"<<endl;
        }
        else{
          var=false;
        }
      }
      string ptype,pname,pemotion;
      int pe,pms,phun;
      file>>ptype;
      file>>pname;
      file>>pe;
      file>>pms;
      file>>phun;
      file>>pemotion;
      if(ptype=="Snake"){
        Snake lsnake(phun,pe,pms,pemotion);
        lsnake.setName(pname);
        string selection;
        while(selection != "q"){
          lsnake.snakePrint();
          cout<<"Energy:"<<lsnake.getEnergy()<<endl;
          cout<<"Mental State:"<<lsnake.getMentalState()<<endl;
          cout<<"Hunger:"<<lsnake.getHunger()<<endl;
          cout<<lsnake.getName()<<" is currently feeling "<<lsnake.getEmotion()<<endl;
          cout<<endl;
          actionMenu(lsnake);
          cin>>selection;

          cout<<endl;
          cout<<endl;
          if(selection =="1"){
            if(lsnake.playMenu()==false){

            }
            else{
              int pa;
              cin>>pa;
              lsnake.Play(pa);
              lsnake.setEmotion();
              if(lsnake.checkDeath()==false){
                cout<<lsnake.getName()<<" bit you..."<<endl;
                cout<<"GAME OVER"<<endl;
                break;
              }
            }
          }
          else if(selection=="2"){
            lsnake.Sfoodmenu();
            int o;
            cin>>o;
            lsnake.Feed(o);
            lsnake.setEmotion();
            if(lsnake.checkDeath()==false){
              cout<<lsnake.getName()<<" bit you..."<<endl;
              cout<<"GAME OVER"<<endl;
              break;
            }



          }
          else if(selection=="3"){
            lsnake.sleep();
            cout<<"enter in anything to wake "<<lsnake.getName()<<" up"<<endl;
            string wake;
            cin>>wake;
            if(lsnake.checkDeath()==false){
              cout<<lsnake.getName()<<" bit you..."<<endl;
              cout<<"GAME OVER"<<endl;
              break;
            }

          }
          if(selection=="q"){
            //file save
            cout<<"Saving progress..."<<endl;
            ofstream ofile;
            ofile.open("savedgame.txt");
            ofile<<lsnake.petType()<<endl;
            ofile<<lsnake.getName()<<endl;
            ofile<<lsnake.getEnergy()<<endl;
            ofile<<lsnake.getMentalState()<<endl;
            ofile<<lsnake.getHunger()<<endl;
            ofile<<lsnake.getEmotion()<<endl;
            cout<<"PROGRESS SAVED!!!"<<endl;
            cout<<endl;

          }

        }


      }




      else if(ptype=="Dog"){
        Dog ldog(phun,pe,pms,pemotion);
        ldog.setName(pname);
        string selection;
        while(selection != "q"){
          ldog.dogPrint();
          cout<<"Energy:"<<ldog.getEnergy()<<endl;
          cout<<"Mental State:"<<ldog.getMentalState()<<endl;
          cout<<"Hunger:"<<ldog.getHunger()<<endl;
          cout<<ldog.getName()<<" is currently feeling "<<ldog.getEmotion()<<endl;
          cout<<endl;
          actionMenu(ldog);
          cin>>selection;

          cout<<endl;
          cout<<endl;
          if(selection =="1"){
            if(ldog.playMenu()==false){

            }
            else{
              int pa;
              cin>>pa;
              ldog.Play(pa);
              ldog.setEmotion();
              if(ldog.checkDeath()==false){
                cout<<ldog.getName()<<" has died..."<<endl;
                cout<<"GAME OVER"<<endl;
                break;
              }
            }
          }
          else if(selection=="2"){
            ldog.Dfoodmenu();
            int o;
            cin>>o;
            ldog.Feed(o);
            ldog.setEmotion();
            if(ldog.checkDeath()==false){
              cout<<ldog.getName()<<" has died..."<<endl;/////////////////
              cout<<"GAME OVER"<<endl;
              break;
            }



          }
          else if(selection=="3"){
            ldog.sleep();
            cout<<"enter in anything to wake "<<ldog.getName()<<" up"<<endl;
            string wake;
            cin>>wake;
            if(ldog.checkDeath()==false){
              cout<<ldog.getName()<<" has died..."<<endl;
              cout<<"GAME OVER"<<endl;
              break;
            }

          }
          if(selection=="q"){
            //file save
            cout<<"Saving progress..."<<endl;
            ofstream ofile;
            ofile.open("savedgame.txt");
            ofile<<ldog.petType()<<endl;
            ofile<<ldog.getName()<<endl;
            ofile<<ldog.getEnergy()<<endl;
            ofile<<ldog.getMentalState()<<endl;
            ofile<<ldog.getHunger()<<endl;
            ofile<<ldog.getEmotion()<<endl;
            cout<<"PROGRESS SAVED!!!"<<endl;
            cout<<endl;

          }

        }

      }











      else if(ptype=="Parrot"){
        Parrot lparrot(phun,pe,pms,pemotion);
        lparrot.setName(pname);
        string selection;
        while(selection != "q"){
          lparrot.parrotPrint();
          cout<<"Energy:"<<lparrot.getEnergy()<<endl;
          cout<<"Mental State:"<<lparrot.getMentalState()<<endl;
          cout<<"Hunger:"<<lparrot.getHunger()<<endl;
          cout<<lparrot.getName()<<" is currently feeling "<<lparrot.getEmotion()<<endl;
          cout<<endl;
          actionMenu(lparrot);
          cin>>selection;

          cout<<endl;
          cout<<endl;
          if(selection =="1"){
            if(lparrot.playMenu()==false){

            }
            else{
              int pa;
              cin>>pa;
              lparrot.Play(pa);
              lparrot.setEmotion();
              if(lparrot.checkDeath()==false){
                cout<<lparrot.getName()<<" flew away..."<<endl;
                cout<<"GAME OVER"<<endl;
                break;
              }
            }
          }
          else if(selection=="2"){
            lparrot.Pfoodmenu();
            int o;
            cin>>o;
            lparrot.Feed(o);
            lparrot.setEmotion();
            if(lparrot.checkDeath()==false){
              cout<<lparrot.getName()<<" flew away..."<<endl;/////////////////
              cout<<"GAME OVER"<<endl;
              break;
            }



          }
          else if(selection=="3"){
            lparrot.sleep();
            cout<<"enter in anything to wake "<<lparrot.getName()<<" up"<<endl;
            string wake;
            cin>>wake;
            if(lparrot.checkDeath()==false){
              cout<<lparrot.getName()<<" flew away..."<<endl;
              cout<<"GAME OVER"<<endl;
              break;
            }

          }
          if(selection=="q"){
            //file save
            cout<<"Saving progress..."<<endl;
            ofstream ofile;
            ofile.open("savedgame.txt");
            ofile<<lparrot.petType()<<endl;
            ofile<<lparrot.getName()<<endl;
            ofile<<lparrot.getEnergy()<<endl;
            ofile<<lparrot.getMentalState()<<endl;
            ofile<<lparrot.getHunger()<<endl;
            ofile<<lparrot.getEmotion()<<endl;
            cout<<"PROGRESS SAVED!!!"<<endl;
            cout<<endl;

          }

        }


      }
    }


    else if(option=="e"){


    }
    else{
      cout<<"invalid option"<<endl;

    }
  }
  cout<<"Exited game, Have a good day!!!";


  return 0;



}
