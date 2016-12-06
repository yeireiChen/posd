#include "Cmd.h"
#include <cstring>
#include <sstream>
#include <map>
#include "MediaDirector.h"
#include "combMediaBuilder.h"
#include "ShapeMediaBuilder.h"


Cmd::Cmd(){}

Cmd::~Cmd(){}


void split(std::string cmd ,std::vector<std::string> *s){   //- def a = Circle(2,1,1)


    std::string temp="";
    char tab2[1024];

    std::strcpy(tab2, cmd.c_str());
    //std::cout << strlen(tab2) <<std::endl;
    for(int i=0; i<strlen(tab2); i++)
    {
        //split command
        if(tab2[i]==' ')
        {
            //std::cout << temp <<std::endl;
            s->push_back(temp);
            temp.clear();
        }
        else
        {
            temp+=tab2[i];
            if(i==strlen(tab2)-1)
            {
                s->push_back(temp);
                temp.clear();
            }
        }
    }
}


void splitDot(std::string number,std::vector<std::string> *s){  //2,1,1
    std::string temp = number;
    std::string temper;
    int last = temp.size();
    int first =0;
    int found ;// temp.find_first_of(")") -- > not found is -1

    //std::cout << "number is " << temp<<std::endl;
    //std::cout << "size is " << last <<std::endl;
    //std::cout << "first appear is "<< temp.find_first_of(",") <<std::endl;

    if(temp.find_first_of(",")!=-1){
        while(temp.find_first_of(",")!=-1){
            //std::cout << "=============" <<std::endl;
            found = temp.find_first_of(",");
            temper = temp.substr(first,found-first);
            s->push_back(temper);
            //std::cout << "number is " << temper <<std::endl;

            temp = temp.substr(found+1,last-found);
            //std::cout << "last number is " << temp<<std::endl;
        }
        s->push_back(temp); //final number need to push
    }

    /*if(s->size()!=0){ //show number
        for(int i=0;i<s->size();i++)
            std::cout << s->at(i) <<std::endl;
    }*/
}

void def(std::string name,std::string formula,std::map<std::string,Media*> *names){

    MediaDirector dc;
    std::vector<std::string> numbers;
    std::string temp=formula;
    std::string typeN;
    std::string number;

    std::cout << name <<"___" <<formula <<std::endl;
    int shLocation = temp.find("(");    //doesn't find is -1
    int shLast = temp.length() - shLocation - 2;

    int cLocation = temp.find("{");     //doesn't find is -1
    int cLast = temp.length() - cLocation - 2;

    if(shLocation!=-1){ // shape()
        //std::cout << "(((----------------------------------------------" <<std::endl;
        //std::cout << "shLocation is " << shLocation <<std::endl;
        //std::cout << "shLast is " << shLast <<std::endl;

        typeN = temp.substr(0,shLocation);
        //std::cout << " typeN is "<<typeN << std::endl;
        number = temp.substr(shLocation+1,shLast);
        //std::cout << " number is "<<number << std::endl;

        if(typeN.compare("Circle")==0){
            //std::cout << "Circle" <<std::endl;
            //std::cout << "number is " << number<<std::endl;
            splitDot(number,&numbers);
            if(numbers.size()!=0) //show number
            {
                for(int i=0; i<numbers.size(); i++)
                    std::cout << numbers.at(i) <<std::endl;
            }

            if(numbers.size()==3){

            }else{
                std::cout << "error parameter " << typeN<<std::endl;
            }
        }
        else if(typeN.compare("Rectangle")==0){
            //std::cout << "Rectangle" <<std::endl;
            //std::cout << "number is " << number<<std::endl;
            splitDot(number,&numbers);
            if(numbers.size()!=0) //show number
            {
                for(int i=0; i<numbers.size(); i++)
                    std::cout << numbers.at(i) <<std::endl;
            }

            if(numbers.size()==4){

            }else{
                std::cout << "error parameter " << typeN<<std::endl;
            }
        }
        else if(typeN.compare("Triangle")==0){
            //std::cout << "Triangle" <<std::endl;
            //std::cout << "number is " << number<<std::endl;
            splitDot(number,&numbers);
            if(numbers.size()!=0) //show number
            {
                for(int i=0; i<numbers.size(); i++)
                    std::cout << numbers.at(i) <<std::endl;
            }

            if(numbers.size()==6){

            }else{
                std::cout << "error parameter " << typeN<<std::endl;
            }
        }
        else{
            std::cout << "error function " << typeN<<std::endl;
        }


    }
    else if(cLocation!=-1){ //combo{}
        //std::cout << "{{{----------------------------------------------" <<std::endl;
        //std::cout << "cLocation is " << cLocation <<std::endl;
        //std::cout << "cLast is " << cLast <<std::endl;

        typeN = temp.substr(0,cLocation);
        //std::cout << " typeN is "<<typeN << std::endl;
        number = temp.substr(cLocation+1,cLast);
        //std::cout << " number is "<<number << std::endl;

        if(typeN.compare("combo")==0){
            //std::cout << "combo" <<std::endl;
            splitDot(number,&numbers);
            if(numbers.size()!=0){
                for(int i=0; i<numbers.size(); i++)
                    std::cout << numbers.at(i) <<std::endl;
            }
        }
        else{
            std::cout << "error function " << typeN <<std::endl;
        }

    }
    else{
        std::cout << "error syntax" <<std::endl;
    }






    //- def a = Circle(2,1,1)
    //- def a = combo{abc,abc}
}

void Cmd::run(){

    std::vector<std::string> cmds ;
    std::map<std::string,Media*> names;
    std::string cmd;


    while(cmd!="exit"){
        std::cout << "enter cmd:" ;
        std::getline(std::cin,cmd);
        //std::cout << "enter cmd is " <<cmd  <<std::endl;'s


        split(cmd,&cmds);
        //std::cout << "size is " << cmds.size() << std::endl;
        if(!cmds.empty()){  //check cmds.at(0)=="-" else continue
            if(cmds.at(0).compare("-")==0 && cmds.size()>=2 && cmds.size()<=5){
                //std::cout << "correct syntax" <<std::endl;
            }
            else{   //error syntax
                std::cout << "error syntax" <<std::endl;
                cmds.clear();
                continue;
            }
            /*if(cmds.at(0).compare("-")!=0 && cmds.size()<2 && cmds.size()>5){
                std::cout << "error syntax" <<std::endl;
                cmds.clear();
                continue;
            }*/

            if(cmds.at(1).compare("def")==0){
                if(cmds.at(3).compare("=")==0 && cmds.size()==5){
                    std::cout << "Action is def" <<std::endl;
                    def(cmds.at(2),cmds.at(4),&names);
                }
                else{  //error syntax

                    std::cout << "error syntax" <<std::endl;
                    cmds.clear();
                    continue;
                }

            }
            else if(cmds.at(1).compare("add")==0){
                std::cout << "Action is add" <<std::endl;
            }
            else if(cmds.at(1).compare("delete")==0){
                std::cout << "Action is delete" <<std::endl;
            }
            else if(cmds.at(1).compare("show")==0){
                std::cout << "Action is show" <<std::endl;
            }
            else{   //area() perimeter()

            }
        }//if cmd's empty



         std::cout << "----------------------------------------------" <<std::endl;

        /*for(int i=0; i<cmds.size(); i++){
            std::cout << cmds.at(i) <<std::endl;
        }*/
        cmds.clear();






    }
}


