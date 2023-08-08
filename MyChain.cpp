//
// Created by paul on 2/23/23.
//

#include "MyChain.h"
#include <iostream>
#include "PatSearch.h"


MyChain::MyChain() {
    std::cout<<"input a nucleotides sequence: ";
std::cin>>this->chain;

std::fstream Write;
Write.open("temp_data.txt",std::ios::out);
if(Write.is_open()){
    Write<<this->chain;
    Write.close();
}


;

std::cout<<"the sequence is long: "<<this->chain.length()<<std::endl;




}



void MyChain::printSequence() {
    int triplets_counter=0;
    char* sequence=this->chain.data();
    std::cout<<"your sequence is: ";
    for(int i=0;i<this->chain.length();i++){
        triplets_counter++;
        std::cout<<sequence[i];
        if(triplets_counter%3==0){std::cout<<" ";}
        if(i==this->chain.length()-1){std::cout<<std::endl;}
    }
    //here it begins the translation into amminos
    int i=0; //beginning of each triple
    int n=3; //ending of each triplet
    int k=0; //counter for the temporary store
    std::string temp; //variable to temporary store amminoacid
    char char_array[3]; //temporary array of 3 nucleotids
    std::string out_string; //buffer of the sequence o amminoacids
    int check=0; //counter of triplets translated into aminos

    while(check<=this->chain.length()-1) {

        for (i; i < n; i++) {
            char_array[k] =sequence[i];
            k++;
        }

        i = n;
        n = n + 3;
        check=check+3;
        k=0; //reset to 0 the counter of triplets
        temp=char_array; //the temporary string is initialized with the value of the array to permit the comparison

        //given that the input is a codon
        if(temp=="UUU" || temp=="UUC"){out_string=out_string + "Phe + ";}
        if(temp=="UUA" || temp=="UUG"){out_string=out_string +"Leu + ";}
        if(temp=="UCU"|| temp=="UCC" || temp=="UCA" || temp=="UCG"){out_string=out_string +"Ser + ";}
        if(temp=="UAU" || temp=="UAC"){out_string=out_string +"Tyr + ";}
        if(temp=="UAA" || temp=="UAG"){out_string=out_string +"STOP";}
        if(temp=="UGU" || temp=="UGC"){out_string=out_string +"Cys + ";}
        if(temp=="UGA"){out_string=out_string +"STOP";}
        if(temp=="UGG"){out_string=out_string +"Trp + ";}
        if(temp=="CUU" || temp=="CUC" || temp=="CUA" || temp=="CUG"){out_string=out_string +"Leu + ";}
        if(temp=="CCU" || temp=="CCC" || temp=="CCA" || temp=="CCG"){out_string=out_string +"Pro + ";}
        if(temp=="CAU" || temp=="CAC"){out_string=out_string +"His + ";}
        if(temp=="CAA" || temp=="CAG"){out_string=out_string +"Gln + ";}
        if(temp=="CGU" || temp=="CGC" || temp=="CGA" || temp=="CGG"){out_string=out_string +"Arg + ";}
        if(temp=="AUU" || temp=="AUC" || temp=="AUA"){out_string=out_string +"Ile + ";}
        if(temp=="AUG"){out_string=out_string +"START/Met + ";}
        if(temp=="ACU" || temp=="ACC" || temp=="ACA" || temp=="ACG"){out_string=out_string +"Thr + ";}
        if(temp=="AAU" || temp=="AAC"){out_string=out_string +"Asn + ";}
        if(temp=="AAA" || temp=="AAG"){out_string=out_string +"Lys + ";}
        if(temp=="AGU" || temp=="AGC"){out_string=out_string +"Ser + ";}
        if(temp=="AGA" || temp=="AGG"){out_string=out_string +"Arh + ";}
        if(temp=="GUU" || temp=="GUC" || temp=="GUA" || temp=="GUG"){out_string=out_string +"Val + ";}
        if(temp=="GCU" || temp=="GCC" || temp=="GCA" || temp=="GCG"){out_string=out_string +"Ala + ";}
        if(temp=="GAU" || temp=="GAC"){out_string=out_string +"Asp + ";}
        if(temp=="GAA" || temp=="GAG"){out_string=out_string +"Glu + ";}
        if(temp=="GGU" || temp=="GGC" || temp=="GGA" || temp=="GGG"){out_string=out_string +"Gly + ";}



    }


    std::cout<<"sequence of amino-acids: "<<out_string<<std::endl;

}





//DESTRUCTOR
MyChain::~MyChain() {
    std::cout<<"your chain has been removed"<<std::endl;
}







//SEQUENCE MODIFIER
void MyChain::modSequence() {
    std::cout<<"1 for adding a portion, 2 for erasing a  portion, 3 for changing a portion"<<std::endl;
    int choice;
    std::cout<<"input your choice: "; std::cin>>choice;

    switch (choice) {

        case 1: {//add a portion
            int position=0;
            char* sequence=this->chain.data();
            std::string new_portion;

                std::cout<<"input the position where to add the new portion: "; std::cin>>position;
                std::cout<<"input the new portion to be added: "; std::cin>>new_portion;


                char before_array[position];
                for(int i=0;i<position;i++){
                    before_array[i]=sequence[i];
                }
                std::fstream First;
                First.open("temp_data.txt",std::ios::app);
                if(First.is_open()){
                    First<<before_array;
                    First.close();
                }

            std::fstream Second;
            First.open("temp_data.txt",std::ios::app);
            if(First.is_open()){
                First<<new_portion;
                First.close();
            }


                char after_array[this->chain.length()+position];
                for(int i=position;i<this->chain.length();i++){
                    after_array[i-position]=sequence[i];
                }

            std::fstream Third;
            First.open("temp_data.txt",std::ios::app);
            if(First.is_open()){
                First<<after_array;
                First.close();
            }




            break;}


                





        case 2:{//remove a portion
            char* sequence=this->chain.data();
            int begin;
            std::cout<<"input position where to start the cutting: ";std::cin>>begin;
            int ending;
            std::cout<<"input the termination of the cut: ";std::cin>>ending;

            char before[begin];
            for(int i=0;i<begin;i++){ //copies everything form 0 to the beginning of the cut into the buffer
                before[i]=sequence[i];
            }
            std::string before_string=before; //the content of the buffer is transferred into a string and then deleted


            char after[this->chain.length()-ending];
            for(int i=ending;i<this->chain.length();i++){ //copies everything from the ending of the cut to the termination of the chain into the buffer (char* after)
                after[i-ending]=sequence[i];
            }
            std::string after_string=after; //the content of the buffer is transferred into a string and then deleted


            std::string new_string=before_string+after_string;
            this->chain=new_string;
            break;}





        case 3:{//change a portion of the chain with a new one
            int num_choice=0;
            std::cout<<"choose if you want to change from position x to y (1), or locate a certain sequence and change it (2): "; std::cin>>num_choice; //input of the two choices



            if(num_choice==2){
                char* sequence=this->chain.data();
                std::string text=this->chain;
                char* text_point=text.data();

                std::string pattern;
                std::cout<<"input the sequence to be searched and changed";
                std::cin>>pattern;
                char* pattern_point=pattern.data();




                //misses the part implementing the change after the search
                std::string new_portion;
                std::cout<<"input the replacement sequence, must be of length "<<pattern.length()<<": "; std::cin>>new_portion;
                char* replacement=new_portion.data();
                for(int i=KMP(text_point,pattern_point);i<(KMP(text_point,pattern_point)+new_portion.length());i++){
                    sequence[i]=replacement[i- KMP(text_point,pattern_point)];
                }
                this->chain=sequence;


            }else{
                char* sequence=this->chain.data();
                int from;
                int to;
                std::string modification;
                std::cout<<"input the position from where to start modifying: ";std::cin>>from;
                std::cout<<"input the termination of the modification: ";std::cin>>to;
                std::cout<<"input the replacement sequence, must be of length:"<<to-from<<" ->";std::cin>>modification;

                char* new_portion=modification.data();
                for(int i=from;i<to;i++){
                    sequence[i]=new_portion[i-from];
                }

                this->chain=sequence;

            }

            break;}
    }


}

void MyChain::compare() {
KMP(read_from(),this->chain);
}




