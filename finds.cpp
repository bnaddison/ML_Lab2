// ADDBRA001 Lab 2

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <memory>
#include <string>
#include <math.h>

using namespace std;

vector < pair<vector<string>,bool> > t_examples;
vector <string> h = {"0", "0", "0", "0", "0", "0"};
//vector<string> examples;

int main () {

    string input, line;
    string sky, airtemp, humidity, wind, water, forecast, enjoy;
  	cout << "Enter Input File name:" << endl;
  	cin >> input;

  	ifstream in(input);

  	while ( getline(in, line) ) {
      bool enjoysport;
  		istringstream ss(line);
  		ss >> sky >> airtemp >> humidity >> wind >> water >> forecast >> enjoy;
      if (enjoy.compare("Yes") == 0) {
        enjoysport = true;
      }
      else {
        enjoysport = false;
      }
      vector<string> example;

      example.push_back(sky);
      example.push_back(airtemp);
      example.push_back(humidity);
      example.push_back(wind);
      example.push_back(water);
      example.push_back(forecast);

      for (int i = 0; i < example.size(); i++) {
        //cout << example[i] << " ";
      }
      //cout << endl;

      pair<vector<string>, bool> x (example, enjoysport);
      t_examples.push_back(x);

    }

    for (int i = 0; i < t_examples.size(); i++) {
      for (int j = 0; j < t_examples[i].first.size(); j++) {
        //cout << t_examples[i].first[j] << " ";
        if (h[j].compare("0")==0) {
          h[j] = t_examples[i].first[j];
        }
        if (h[j].compare(t_examples[i].first[j]) != 0 && t_examples[i].second == true) {
          h[j] = "?";
        }
        /*
        if (h[j].compare(t_examples[i].first[j]) == 0 && t_examples[i].second == false) {
          h[j] = "?";
        }
        */


      }
      //cout << endl;
      //cout << i+1 << " " << t_examples[i].second << endl;
    }

    ofstream out;
  	out.open("Outputfile");

    if (out.is_open()) {
      for (int i = 0; i < h.size(); i++) {
        out << h[i] << " ";
      }
    }
    out.close();

    for (int i = 0; i < h.size(); i++) {
      cout << h[i] << " ";
    }
    cout << endl;




  return 0;
}
