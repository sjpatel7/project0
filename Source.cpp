#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
	//100x100 array "c" of zeros
	int c[100][100];
	fill(c[0], c[100], 0);

	//filling right side of c with 1's (coffee)
	for (int i = 0; i<100; i++) {
		for (int j = 50; j<100; j++) {
			c[i][j] = 1;
		}
	}
		  //coffee and cream switching loop
		  //randomly pick neighboring coffee and cream cells and swap 
		  //identify neighboring cells. load up spots in array. randomly pick spots from array then switch
	for (int n = 0; n < 2001;n++) { //iterates over 2000 steps for swapping of whole grid
		vector<int> nbi; //nbi holds row entry of neighboring coffee and cream cells
		vector<int> nbj; //nbj holds column entry of neighboring coffee and cream cells	
		for (int i = 1; i < 99; i++) {  //first we apply the transition rule to the grid (not the border cells)
			for (int j = 1; j < 99; j++) {

				//these if statements check for neighboring different cells and updates nbj and nbi

				if (c[i][j] != c[i - 1][j]) { //spot up
					nbi.push_back(i);
					nbi.push_back(i - 1);
					nbj.push_back(j);
					nbj.push_back(j);
				}
				if (c[i][j] != c[i + 1][j]) { //spot down
					nbi.push_back(i);
					nbi.push_back(i + 1);
					nbj.push_back(j);
					nbj.push_back(j);
				}
				if (c[i][j] != c[i][j - 1]) { //spot left
					nbi.push_back(i);
					nbi.push_back(i);
					nbj.push_back(j - 1);
					nbj.push_back(j);
				}
				if (c[i][j] != c[i][j + 1]) { //spot right
					nbi.push_back(i);
					nbi.push_back(i);
					nbj.push_back(j + 1);
					nbj.push_back(j);
				}
			}
		}
					int x = nbi.size(); //nbj and nbi should be same size
					for(int l=0;l<x/10;l++){ //randomly swaps x/10 neighboring cells
						if (x != 0) {
						int y = rand() % x; //picks out random entry of nbi and nbj pair for swap
						
						if (y % 2 == 0) { //if y is even. vector goes in pairs of (even odd) element spots
							int a=c[nbi[y]][nbj[y]];
							int b=c[nbi[y + 1]][nbj[y + 1]]; 
						//swapping procedure
							c[nbi[y]][nbj[y]] = b;
							c[nbi[y + 1]][nbj[y + 1]]=a;
						}
						else { //if y is odd
							int a = c[nbi[y]][nbj[y]];
							int b = c[nbi[y - 1]][nbj[y - 1]];
							c[nbi[y]][nbj[y]] = b;
							c[nbi[y - 1]][nbj[y - 1]] = a;
						}
						}	
					}
		
			//corners
			vector<int> nbci;
			vector<int> nbji;
			if (c[0][0] != c[1][0]) { //top left corner
				nbci.push_back(0);
				nbci.push_back(1);
				nbji.push_back(0);
				nbji.push_back(0);
			}
			if (c[0][0] != c[0][1]) {
				nbci.push_back(0);
				nbci.push_back(0);
				nbji.push_back(0);
				nbji.push_back(1);
			}
			x = nbci.size();
			if (x != 0) {
				int y = rand() % x; //picks out random entry of nbi and nbj pair for swap
				if (y % 2 == 0) { //if y is even. vector goes in pairs of (even odd) element spots
					int a = c[nbci[y]][nbji[y]];
					int b = c[nbci[y + 1]][nbji[y + 1]];
					c[nbci[y]][nbji[y]] = b;
					c[nbci[y + 1]][nbji[y + 1]]=a;
				}
				else { //if y is odd
					int a = c[nbci[y]][nbji[y]];
					int b = c[nbci[y - 1]][nbji[y - 1]];
					c[nbci[y]][nbji[y]] = b;
					c[nbci[y-1]][nbji[y-1]] = a;
				}
			}
			nbci.clear();
			nbji.clear();

			if (c[99][0] != c[98][0]) { //bottom left
				nbci.push_back(99);
				nbci.push_back(98);
				nbji.push_back(0);
				nbji.push_back(0);
			}
			if (c[99][0] != c[99][1]) {
				nbci.push_back(99);
				nbci.push_back(99);
				nbji.push_back(0);
				nbji.push_back(1);
			}
			x = nbci.size();
			if (x != 0) {
				int y = rand() % x; //picks out random entry of nbi and nbj pair for swap
				if (y % 2 == 0) { //if y is even. vector goes in pairs of (even odd) element spots
					int a = c[nbci[y]][nbji[y]];
					int b = c[nbci[y + 1]][nbji[y + 1]];
					c[nbci[y]][nbji[y]] = b;
					c[nbci[y + 1]][nbji[y + 1]] = a;
				}
				else { //if y is odd
					int a = c[nbci[y]][nbji[y]];
					int b = c[nbci[y - 1]][nbji[y - 1]];
					c[nbci[y]][nbji[y]] = b;
					c[nbci[y - 1]][nbji[y - 1]] = a;
				}
			}
			nbci.clear();
			nbji.clear();
			if (c[0][99] != c[0][98]) { //top right
				nbci.push_back(0);
				nbci.push_back(0);
				nbji.push_back(99);
				nbji.push_back(98);
			}
			if (c[0][99] != c[1][99]) {
				nbci.push_back(0);
				nbci.push_back(1);
				nbji.push_back(99);
				nbji.push_back(99);
			}

			x = nbci.size();
			
			if (x != 0) {
				int y = rand() % x; //picks out random entry of nbi and nbj pair for swap
				if (y % 2 == 0) { //if y is even. vector goes in pairs of (even odd) element spots
					int a = c[nbci[y]][nbji[y]];
					int b = c[nbci[y + 1]][nbji[y + 1]];
					c[nbci[y]][nbji[y]] = b;
					c[nbci[y + 1]][nbji[y + 1]] = a;
				}
				else { //if y is odd
					int a = c[nbci[y]][nbji[y]];
					int b = c[nbci[y - 1]][nbji[y - 1]];
					c[nbci[y]][nbji[y]] = b;
					c[nbci[y - 1]][nbji[y - 1]] = a;
				}
				}
			
			nbci.clear();
			nbji.clear();
			if (c[99][99] != c[98][99]) { //bottom right
				nbci.push_back(99);
				nbci.push_back(98);
				nbji.push_back(99);
				nbji.push_back(99);
			}
			if (c[99][99] != c[99][98]) {
				nbci.push_back(99);
				nbci.push_back(99);
				nbji.push_back(99);
				nbji.push_back(98);
			}

			x = nbci.size();
			if (x != 0) {
				int y = rand() % x; //picks out random entry of nbi and nbj pair for swap
				if (y % 2 == 0) { //if y is even. vector goes in pairs of (even odd) element spots
					int a = c[nbci[y]][nbji[y]];
					int b = c[nbci[y + 1]][nbji[y + 1]];
					c[nbci[y]][nbji[y]] = b;
					c[nbci[y + 1]][nbji[y + 1]] = a;
				}
				else { //if y is odd
					int a = c[nbci[y]][nbji[y]];
					int b = c[nbci[y - 1]][nbji[y - 1]];
					c[nbci[y]][nbji[y]] = b;
					c[nbci[y - 1]][nbji[y - 1]] = a;
				}
			}
			nbci.clear();
			nbji.clear();

			if (n == 0) {
				ofstream myfile;
				myfile.open("state0.txt");

				for (int q = 0; q < 100; q++) {
					for(int r=0;r<100;r++){
						myfile << c[q][r]<<",";
					}
				}
				myfile.close();

				//load grid array at 1st iteration into file "state0.txt"
			}
			if (n == 800) {
				ofstream myfile;
				myfile.open("state80.txt");
				for (int q = 0; q < 100; q++) {
					for (int r = 0; r<100; r++) {
						myfile << c[q][r]<<",";
					}
				}
				myfile.close();
				//load grid array at 801st iteration into file "state80.txt"
			}
			if (n == 2000) {
				ofstream myfile;
				myfile.open("state200.txt");
				for (int q = 0; q < 100; q++) {
					for (int r = 0; r<100; r++) {
						myfile << c[q][r]<<",";
					}
				}
				myfile.close();
				//load grid array at 2001st iteration into file "state200.txt"
			}
		}
		
		
		return 0;
}
