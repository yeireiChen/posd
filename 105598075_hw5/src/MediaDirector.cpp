#include "MediaDirector.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"



using namespace std;

MediaDirector::MediaDirector(){}

MediaDirector::~MediaDirector(){}

void MediaDirector::setMediaBuilder(std::stack<MediaBuilder*> *mbs){

}
void MediaDirector::concrete(std::string content){

    char tab2[1024];
    std::strcpy(tab2, content.c_str());
    /*for(int i=0;i<std::strlen(tab2);i++){ //show
        std::cout << tab2[i];
    }
    std::cout << "" <<std::endl;*/

    /****************************************************************************/

    std::string temp;
    std::string temper;
    std::string change;
    //std::stack<std::string> botton;
    std::stack<std::string> sequence;
    std::vector<std::string> vsequence;
    /*************/

    for(int i=0;i<strlen(tab2);i++){

        if(tab2[i]==' ' && tab2[i-1]==')')
            continue;
        else
            temp+=tab2[i];


        if (tab2[i]=='('){
            //botton.push(temp);
            vsequence.push_back(temp);
            temp.clear();
        }
        else if (tab2[i]==')' && tab2[i+1]==' '){
            //change=botton.top()+temp;
            //botton.pop();
            //botton.push(change);
            change = vsequence.back()+temp;
            vsequence.pop_back();
            vsequence.push_back(change);
            temp.clear();
        }
        else if(tab2[i]==')'){
            //botton.push(temp);
            vsequence.push_back(temp);
            temp.clear();
        }

    }


    std::cout << "_________________________________________________________" <<std::endl;

    for(int i=0;i<vsequence.size();i++){

        if (i==0 || i==vsequence.size()-1){
            //continue;
            std::cout << vsequence.at(i)<<std::endl;
        }
        else{
            std::cout << vsequence.at(i)<<std::endl;
        }
    }
    std::cout << "111_________________________________________________________" <<std::endl;

    std::vector<std::string> num2 ;
    int length;
    int ntemp=0;//delete

    for(int i=0;i<vsequence.size();i++){

        if(vsequence.at(i).compare("combo(")==0){
            if(i==0)
                std::cout << i << " is "<< vsequence.at(i) <<std::endl;
            else
                std::cout << vsequence.at(i) <<std::endl;
        }
        else if (vsequence.at(i).compare(")")==0){
            if(i==vsequence.size()-1)
                std::cout << i << " is "<< vsequence.at(i) <<std::endl;
            else
                std::cout << vsequence.at(i) <<std::endl;
        }
        else{
            length = vsequence.at(i).length();
            temp = vsequence.at(i).substr(2,length-3);  //split number
            //std::cout << "..."<<temp <<std::endl;
            std::stringstream ss(temp);//start
            while (ss >> temp)
                num2.push_back(temp);  //end to split white space_(10 0 2)->10,0,2

            //ntemp+=atoi(num2.at(i).c_str());
            if(vsequence.at(i).at(0)=='r'){
                //std::cout << "r(" <<std::endl;
                std::cout << "r(" <<num2.at(0)<<" "<<num2.at(1)<<" "<<num2.at(2)<<" "<<num2.at(3)<<")"<<std::endl;
            }else if(vsequence.at(i).at(0)=='c'){
                //std::cout << "c(" <<std::endl;
                std::cout << "c(" <<num2.at(0)<<" "<<num2.at(1)<<" "<<num2.at(2)<<")"<<std::endl;
            }else if (vsequence.at(i).at(0)=='t'){
                //std::cout << "t(" <<std::endl;
                std::cout << "t(" <<num2.at(0)<<" "<<num2.at(1)<<" "<<num2.at(2)<<" "<<num2.at(3)<<" "<<num2.at(4)<<" "<<num2.at(5)<<")"<<std::endl;

            }

            num2.clear();//initialize number vector

        }


    }//end for

    std::cout << "_________________________________________________________" <<std::endl;




    std::cout << "_________________________________________________________" <<std::endl;

}

