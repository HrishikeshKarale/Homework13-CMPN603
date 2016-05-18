
#include<iostream>
#include <vector>
#include <stack>
#include <queue>
#include<fstream>
#include<stdlib.h>
#include<string>

using namespace std;

class Llyod{
	Llyod();
	~Llyod();
};

Llyod::Llyod(){
}

Llyod::~Llyod(){
}

class State{
	public:
		State(){
		}
    ~State(){
    }
		//board representation
		char board[10][10];
		State *parent;
	};

//queue for storing configurations
queue<State*> config;
//for storing visited states
vector<State*>visitedstate;
//iterator to traverse the vector
vector<State>::iterator i;




bool visited(State *vtemp, int height,int width){




	//for checking each and every visited state
	for (int k=0; k<(int)visitedstate.size(); ++k){
		//chechking with the state provided
		bool flag = true;
		//checking the container values
		for (int j = 0; j < height && flag; j++){
			for (int i = 0; i < width && flag; i++){
				if ((int)vtemp->board[j][i]==(int)visitedstate.at(k)->board[j][i]){
					flag = true;
				}
				else{
					flag = false;
				}
			}
		}
		if (flag == false){
			continue;
		}
		else{
		cout<<"VISITED: true"<<endl;
			return true;
		}
	}
			cout<<"VISITED: false"<<endl;

	return  false;
}

bool goal_check(State *gtemp, int height,int width,State *goal){
	bool flag = true;
	//checking the container values
	for (int j = 0; j < height && flag; j++){
		for (int i = 0; i < width && flag; i++){
			if ((int)gtemp->board[j][i]==(int)goal->board[j][i]){
				flag = true;
			}
			else{
				flag = false;
			}
		}
		return flag;
	}
	return flag;
}






void configsolver(State ctemp, int height, int width){
	char temp;
	State p=ctemp;
	State *ctemp1= new State();
	State *ctemp2= new State();
	State *ctemp3= new State();
	State *ctemp4= new State();
	
	//locate the spaces
	vector<int>locatex;
	vector<int>locatey;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (ctemp.board[i][j] == '.'){
				locatex.push_back(i);
				locatey.push_back(j);
				cout << i<<" "<<j<<endl;
			}
		}
	}
	 cout<<"\ndone!!"<<endl;
	for (int i = 0; i <(int)locatex.size(); i++) {
 //   cout<<"for"<<endl;
	  if (locatex.at(i) == 0 || locatex.at(i) == height - 1){
  //    cout<<"for if"<<endl;
			if (locatey.at(i) != 0 && locatey.at(i) != width - 1){
//        cout<<"for if if"<<endl;
				temp = ctemp.board[locatex.at(i)][locatey.at(i) - 1];
				cout<<"TEMP: "<<temp<<endl;
				ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
				ctemp.board[locatex.at(i)][locatey.at(i) - 1] = 46;
			
				*ctemp1=ctemp;
				
				config.push(ctemp1);
				
        ctemp.board[locatex.at(i)][locatey.at(i) - 1] = temp;
				ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
        //other
				temp = ctemp.board[locatex.at(i)][locatey.at(i) + 1];
				cout<<"TEMP: "<<temp<<endl;
				ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
				ctemp.board[locatex.at(i)][locatey.at(i) + 1] = 46;
				
				*ctemp2= ctemp;
				
				config.push(ctemp2);
				
        ctemp.board[locatex.at(i)][locatey.at(i) + 1] = temp;
				ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
        
			}
			else {
  //      cout<<"for if if-else if"<<endl;
      	if (locatex.at(i) == 0 && locatey.at(i) == 0){
					temp = ctemp.board[locatex.at(i) + 1][locatey.at(i)];
					cout<<"TEMP: "<<temp<<endl;
				  ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i) + 1][locatey.at(i)] = 46;
					
					*ctemp1= ctemp;
					
					config.push(ctemp1);
				  ctemp.board[locatex.at(i) + 1][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
        	//other
					temp = ctemp.board[locatex.at(i)][locatey.at(i) + 1];
    			cout<<"TEMP: "<<temp<<endl;
					ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i) + 1] = 46;
				
					ctemp.board[locatex.at(i)][locatey.at(i) + 1] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
       }
				else if (locatex.at(i) == 0 && locatey.at(i) == width - 1){
  //        cout<<"for if if-else if-elseif 1"<<endl;
					temp = ctemp.board[locatex.at(i) + 1][locatey.at(i)];
    			cout<<"TEMP: "<<temp<<endl;
					ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i) + 1][locatey.at(i)] = 46;
					
					*ctemp1= ctemp;
					
					config.push(ctemp1);
					ctemp.board[locatex.at(i) + 1][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
					//other
					temp = ctemp.board[locatex.at(i)][locatey.at(i) - 1];
    			cout<<"TEMP: "<<temp<<endl;
					ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i) - 1] = 46;
					*ctemp2= ctemp;
					
					config.push(ctemp2);
					ctemp.board[locatex.at(i)][locatey.at(i) - 1] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
				 }
				else if (locatex.at(i) == height - 1 && locatey.at(i) == 0) {
    //      cout<<"for if if-else if-elseif 2"<<endl;
					temp = ctemp.board[locatex.at(i) - 1][locatey.at(i)];
    			cout<<"TEMP: "<<temp<<endl;
					ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i) - 1][locatey.at(i)] = 46;
					*ctemp1= ctemp;
					
					config.push(ctemp1);
				   ctemp.board[locatex.at(i) - 1][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
				   //other
					temp = ctemp.board[locatex.at(i)][locatey.at(i) + 1];
    			cout<<"TEMP: "<<temp<<endl;
					ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i) + 1] = 46;
					*ctemp2= ctemp;
					
					config.push(ctemp2);
				   ctemp.board[locatex.at(i)][locatey.at(i) + 1] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
					cout<<"RESET"<<endl;
          for (int k = 0; k < height; k++){
            for (int j = 0; j < width; j++) {
          	  cout << ctemp.board[k][j] << "  ";
          	}
          	cout << endl;
          }
				}
				else if (locatex.at(i) == height - 1 && locatey.at(i) == width - 1) {
//          cout<<"for if if-else if-elseif 3"<<endl;
					temp = ctemp.board[locatex.at(i) - 1][locatey.at(i)];
    			cout<<"TEMP: "<<temp<<endl;
					ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i) - 1][locatey.at(i)] = 46;
					
					*ctemp1= ctemp;
					
					config.push(ctemp1);
				   ctemp.board[locatex.at(i) - 1][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
	        //other
					temp = ctemp.board[locatex.at(i)][locatey.at(i) - 1];
    			cout<<"TEMP: "<<temp<<endl;
					ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i) - 1] = 46;
					
					*ctemp2= ctemp;
					
					config.push(ctemp2);
				   ctemp.board[locatex.at(i)][locatey.at(i) - 1] = temp;
					ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
				
				}
			}
		}
    else if ((locatex.at(i) != 0 && locatex.at(i) != height - 1) && (locatey.at(i) == 0 || locatex.at(i) == width - 1)){
  //    cout<<"for if-elseif"<<endl;
			temp = ctemp.board[locatex.at(i) + 1][locatey.at(i)];
			cout<<"TEMP: "<<temp<<endl;
			ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp.board[locatex.at(i) + 1][locatey.at(i)] = 46;

			*ctemp1= ctemp;
					
			config.push(ctemp1);
			ctemp.board[locatex.at(i)][locatey.at(i) - 1] = temp;
			ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
			//other
			temp = ctemp.board[locatex.at(i) - 1][locatey.at(i)];
			cout<<"TEMP: "<<temp<<endl;
			ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp.board[locatex.at(i) - 1][locatey.at(i)] = 46;

			*ctemp2= ctemp;
					
			config.push(ctemp2);
			ctemp.board[locatex.at(i) - 1][locatey.at(i)] = temp;
			ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
			
    }
		else {
    //  cout<<"for if-else"<<endl;
			temp = ctemp.board[locatex.at(i) + 1][locatey.at(i)];
			cout<<"TEMP: "<<temp<<endl;
			ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp.board[locatex.at(i) + 1][locatey.at(i)] = 46;

			*ctemp1= ctemp;
					
			config.push(ctemp1);
		  ctemp.board[locatex.at(i)][locatey.at(i) - 1] = temp;
			ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
			//other
			temp = ctemp.board[locatex.at(i) - 1][locatey.at(i)];
			cout<<"TEMP: "<<temp<<endl;
			ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp.board[locatex.at(i) - 1][locatey.at(i)] = 46;

			*ctemp2= ctemp;
					
			config.push(ctemp2);
			ctemp.board[locatex.at(i) - 1][locatey.at(i)] = temp;
			ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
			//other
			temp = ctemp.board[locatex.at(i)][locatey.at(i) + 1];
			cout<<"TEMP: "<<temp<<endl;
			ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp.board[locatex.at(i)][locatey.at(i) + 1] = 46;
			
			*ctemp3= ctemp;
					
			config.push(ctemp3);
		   ctemp.board[locatex.at(i)][locatey.at(i) + 1] = temp;
			ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
		   //other
			temp = ctemp.board[locatex.at(i)][locatey.at(i) - 1];
			cout<<"TEMP: "<<temp<<endl;
			ctemp.board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp.board[locatex.at(i)][locatey.at(i) - 1] = 46;
			
			*ctemp4= ctemp;
					
			config.push(ctemp4);
			ctemp.board[locatex.at(i)][locatey.at(i) - 1] = temp;
			ctemp.board[locatex.at(i)][locatey.at(i)] = 46;
		 }
	}
}



int main(int argc, char* argv[]) {
	
    int height = 0;
    int width = 0;
	//initial conditions
	 State *temp = new State();
	  State *goal=new State();
	string line;
	
	if(argc==3){
	    if(argv[1]!="-"){
	        ifstream infile(argv[1]);
	        getline(infile, line);
	        width= (int)line[0]-48;
	        height= (int)line[2]-48;
	        for(int i=0; i<height; i++){
	         getline(infile, line);
	          for(int j=0; j<width; j++){
	              temp->board[i][j]= line[j];
	          }
	        }
    		getline(infile, line);
    		for(int i=0; i<height; i++){
	         getline(infile, line);
	          for(int j=0; j<width; j++){
	              goal->board[i][j]= line[j];
	          }
	        }
	    }
	    else{
    		cout<<"Enter height and width: ";
    		cin>>height>>width;
            cout<<"Enter initial board Configuration: "<<endl;
    		for(int i=0; i<height; i++){
    			for(int j=0; j<width; j++){
    			    cout<<"Enter for position ["<<(i+1)<<", "<<(j+1)<<"]: ";
        			cin>>temp->board[i][j];
    			}
    	  }
            cout<<"Enter goal board Configuration: "<<endl;
    		for(int i=0; i<height; i++){
    			for(int j=0; j<width; j++){
    			    cout<<"Enter for position ["<<(i+1)<<", "<<(j+1)<<"]: ";
        			cin>>goal->board[i][j];
    	     }
    		}
    	}
    	cout<<" Width: "<<width<<"\n Height:"<<height<<endl;
    	
    	cout<<" Initial BOARD Confiugration: "<<endl;
    	for (int i = 0; i < height; i++) {
    		for (int j = 0; j < width; j++) {
    			cout << temp->board[i][j] << " ";
    		}
    		cout << endl;
    	}
    	cout<<" Goal BOARD Configuration:"<<endl;
    	for (int i = 0; i < height; i++) {
    		for (int j = 0; j < width; j++) {
    			cout << goal->board[i][j] << " ";
    		}
    		cout << endl;
    	}

    	//pushing it into the configuration queue
    	temp->parent = NULL;


int ii=0;
    	

      config.push(temp);
    	int flag = 1;
    	//when the queue is not empty
    	while (!config.empty()) {
    		//check whether it matches the goal
 /*   if(ii==12){
		  cout<<"GOAL reached: \n";
		  for (int i = 0; i < height; i++){
				for (int j = 0; j < width; j++) {
					cout << goal->board[i][j] << "  ";
				}
				cout << endl;
		  }
		  			return 0;
    }
 */   cout<<"\nCOUNT: "<<(++ii)<<endl;
    
    cout << "qf: \n";
    			for (int i = 0; i < height; i++){
    				for (int j = 0; j < width; j++) {
    					cout << config.front()->board[i][j] << "  ";
    				}
    				cout << endl;
    			}
    		if (goal_check(config.front(), height, width, goal))
    		{
    			cout << "visited goal";
    			flag = 0;
    			break;
    		}
    		
    		//check whether it already arrived at the state
    		if (visited(config.front(), height, width)) {
    		  config.pop();
        }
    		else{
/*      	cout << "qf: \n";
    			for (int i = 0; i < height; i++){
    				for (int j = 0; j < width; j++) {
    					cout << config.front()->board[i][j] << "  ";
    				}
    				cout << endl;
    			}
*/	
    		  //if not visited push into visited state 
    			visitedstate.push_back(config.front());
    			//generate various configuration
      		configsolver(*config.front(), height, width);
          //pop it from queue
    			config.pop();
    			
          
    		}
    	}
    	
    	//if flag=0 puzzle solved       
    	if (flag == 0) {
    		cout << "puzzle solved"<<endl;
    		
    	//	stack<State*> sol;
    	//	State *temp;
    	//	temp = &config.front();
    	
    
    	}
    	//no solution for the puzzle
    	else {
    		cout << "no solution"<<endl;
    	}

	}
	else{
	    cout<<"Please Enter two Commandline parameters"<<endl;
	}
	return 0;
}


