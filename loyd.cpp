
#include<iostream>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>

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

		//board representation
		int board[10][10];
		State *parent;
	};

//queue for storing configurations
static queue<State*> config;
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
				if (vtemp->board[j][i]==visitedstate.at(k)->board[j][i]){
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
			return true;
		}
	}
	return  false;
}

bool goal_check(State *gtemp, int height,int width,State *goal){
	bool flag = true;
	//checking the container values
	for (int j = 0; j < height && flag; j++){
		for (int i = 0; i < width && flag; i++){
			if (gtemp->board[j][i] == goal->board[j][i]){
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

void configsolver(State *ctemp, int height, int width){
	int temp;
	State *p = ctemp;
	//locate the spaces
	vector<int>locatex;
	vector<int>locatey;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (ctemp->board[i][j] == 46){
				locatex.push_back(i);
				locatex.push_back(j);
				cout << i;
			}
		}
	}
	for (int i = 0; i <(int)locatex.size(); i++) {
		if (locatex.at(i) == 0 || locatex.at(i) == height - 1){
			if (locatey.at(i) != 0 && locatey.at(i) != width - 1){
				temp = ctemp->board[locatex.at(i)][locatey.at(i) - 1];
				ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
				ctemp->board[locatex.at(i)][locatey.at(i) - 1] = 46;
				config.push(ctemp);
				ctemp->board[locatex.at(i)][locatey.at(i) - 1] = temp;
				ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
				//other
				temp = ctemp->board[locatex.at(i)][locatey.at(i) + 1];
				ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
				ctemp->board[locatex.at(i)][locatey.at(i) + 1] = 46;
				config.push(ctemp);
				ctemp->board[locatex.at(i)][locatey.at(i) + 1] = temp;
				ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
			}
			else {

				if (locatex.at(i) == 0 && locatey.at(i) == 0){

					temp = ctemp->board[locatex.at(i) + 1][locatey.at(i)];
					ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i) + 1][locatey.at(i)] = 46;
					config.push(ctemp);
					ctemp->board[locatex.at(i) + 1][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
					//other
					temp = ctemp->board[locatex.at(i)][locatey.at(i) + 1];
					ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i) + 1] = 46;
					config.push(ctemp);
					ctemp->board[locatex.at(i)][locatey.at(i) + 1] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i)] = 46;

				}
				else if (locatex.at(i) == 0 && locatey.at(i) == width - 1){
					temp = ctemp->board[locatex.at(i) + 1][locatey.at(i)];
					ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i) + 1][locatey.at(i)] = 46;
					config.push(ctemp);
					ctemp->board[locatex.at(i) + 1][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
					//other
					temp = ctemp->board[locatex.at(i)][locatey.at(i) - 1];
					ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i) - 1] = 46;
					config.push(ctemp);
					ctemp->board[locatex.at(i)][locatey.at(i) - 1] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
				}
				else if (locatex.at(i) == height - 1 && locatey.at(i) == 0) {
					temp = ctemp->board[locatex.at(i) - 1][locatey.at(i)];
					ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i) - 1][locatey.at(i)] = 46;
					config.push(ctemp);
					ctemp->board[locatex.at(i) - 1][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
					//other
					temp = ctemp->board[locatex.at(i)][locatey.at(i) + 1];
					ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i) + 1] = 46;
					config.push(ctemp);
					ctemp->board[locatex.at(i)][locatey.at(i) + 1] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
				}
				else if (locatex.at(i) == height - 1 && locatey.at(i) == width - 1) {
					temp = ctemp->board[locatex.at(i) - 1][locatey.at(i)];
					ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i) - 1][locatey.at(i)] = 46;
					config.push(ctemp);
					ctemp->board[locatex.at(i) - 1][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
					//other
					temp = ctemp->board[locatex.at(i)][locatey.at(i) - 1];
					ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i) - 1] = 46;
					config.push(ctemp);
					ctemp->board[locatex.at(i)][locatey.at(i) - 1] = temp;
					ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
				}


			}
		}
		else if ((locatex.at(i) != 0 && locatex.at(i) != height - 1) && (locatey.at(i) == 0 || locatex.at(i) == width - 1)){
			temp = ctemp->board[locatex.at(i) + 1][locatey.at(i)];
			ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp->board[locatex.at(i) + 1][locatey.at(i)] = 46;
			config.push(ctemp);
			ctemp->board[locatex.at(i)][locatey.at(i) - 1] = temp;
			ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
			//other
			temp = ctemp->board[locatex.at(i) - 1][locatey.at(i)];
			ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp->board[locatex.at(i) - 1][locatey.at(i)] = 46;
			config.push(ctemp);
			ctemp->board[locatex.at(i) - 1][locatey.at(i)] = temp;
			ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
		}
		else {
			temp = ctemp->board[locatex.at(i) + 1][locatey.at(i)];
			ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp->board[locatex.at(i) + 1][locatey.at(i)] = 46;
			config.push(ctemp);
			ctemp->board[locatex.at(i)][locatey.at(i) - 1] = temp;
			ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
			//other
			temp = ctemp->board[locatex.at(i) - 1][locatey.at(i)];
			ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp->board[locatex.at(i) - 1][locatey.at(i)] = 46;
			config.push(ctemp);
			ctemp->board[locatex.at(i) - 1][locatey.at(i)] = temp;
			ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
			//other
			temp = ctemp->board[locatex.at(i)][locatey.at(i) + 1];
			ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp->board[locatex.at(i)][locatey.at(i) + 1] = 46;
			config.push(ctemp);
			ctemp->board[locatex.at(i)][locatey.at(i) + 1] = temp;
			ctemp->board[locatex.at(i)][locatey.at(i)] = 46;
			//other
			temp = ctemp->board[locatex.at(i)][locatey.at(i) - 1];
			ctemp->board[locatex.at(i)][locatey.at(i)] = temp;
			ctemp->board[locatex.at(i)][locatey.at(i) - 1] = 46;
			config.push(ctemp);
			ctemp->board[locatex.at(i)][locatey.at(i) - 1] = temp;
			ctemp->board[locatex.at(i)][locatey.at(i)] = 46;



		}

	}
}


int main(int argc, char* argv[]) {
	int height = 0;
	int width = 0;
	State *temp = new State();
	State *goal=new State();
	string line;
	if(argv[1]=="-") {	
		cout<<"Please Enter no of rows and columns: ";
		cin>>height>>width;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cin>>temp->board[i][j];
	}	
	else {
height=4;
width=1;
		ifstream myfile(argv[1]);
		if(myfile.is_open()) {
			getline (myfile, line)
			cout<<line.charAt(0)<<endl;
			cout<<line.charAt(2)<<endl;
			cout<<length<<" "<<width<<endl;
			int i=0, j=width;
			while(getline (myfile, line) {
			while(j!=0) {
				temp->board[i][j]= line.charAt[j];
				j--;
			}
			i++;
			getline (myfile, line);
			cout<<line<<endl;
			if(i==length) {
				i=0;
				j=width;
				while(getline (myfile, line) {
				while(j!=0) {
					goal->board[i][j]= line.charAt[j];
					j--;
				}
				i++;
			}
		}
	}

	
	cout<<"Temp BOARD:"<<endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << temp->board[i][j] << " ";
		}
		cout << endl;
	}

	cout<<"Goal BOARD:"<<endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << goal->board[i][j] << " ";
		}
		cout << endl;
	}


	//pushing it into the configuration queue
	temp->parent = NULL;
	config.push(temp);
	int flag = 1;
	//when the queue is not empty
	while (!config.empty()) {
		//check whether it matches the goal

		if (goal_check(config.front(), height, width, goal))
		{
			cout << "visited goal";
			flag = 0;
			break;
		}
		//check whether it already arrived at the state
		if (visited(config.front(), height, width)) {
			//cout << "visited previously" << endl;
			config.pop();
		}
		else {
			cout << "qf: ";
			for (int i = 0; i < height; i++){
				for (int j = 0; j < width; j++) {
					cout << config.front()->board[i][j] << "  ";
				}
				cout << endl;
			}
			//if not visited push into visited state 
			visitedstate.push_back(config.front());
			//generate various configuration
			configsolver(config.front(), height, width);
			//pop it from queue
			config.pop();

		}
	}

	//if flag=0 puzzle solved       
	if (flag == 0) {
		cout << "puzzle solved";
		
	//	stack<State*> sol;
	//	State *temp;
	//	temp = &config.front();
	

	}
	//no solution for the puzzle
	else {
		cout << "no solution";
	}
	int x;
	cin >> x;
	return 0;
}
