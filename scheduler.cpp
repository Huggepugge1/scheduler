#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> groups;
  vector<string> classes;
  vector<pair<int, int>> times = {make_pair(9, 0), make_pair(10, 0), make_pair(12, 30), make_pair(14, 0), make_pair(15, 0)};

  int num_groups, num_classes;
  cout << "Number of groups and classes: ";
  cin >> num_groups >> num_classes;

  cout << "Group names: ";
  for ( int i = 0; i < num_groups; i++ ) {
    string current_group;
    cin >> current_group;
    groups.push_back(current_group);
  }

  cout << "Class names: ";
  for ( int i = 0; i < num_classes; i++ ) {
    string current_class;
    cin >> current_class;
    classes.push_back(current_class);
  }
  
  map<string, map<pair<int, int>, string>> lessons;  // {group, {(time), class}]
  map<string, map<pair<int, int>, bool>> ongoing;  // {class, {(time), avail}}
  map<string, map<string, bool>> taken;  // {class, group}

  for ( string clas : classes ) {
    for ( pair<int, int> time : times ) {
      ongoing[clas][time] = false;
    }
  }

  for ( string group : groups ) {
    for ( pair<int, int> time : times ) {
      lessons[group][time] == "";
    }
  }

  for ( string clas : classes ) {
    for ( string group : groups ) {
      taken[clas][group] = false;
    }
  }
  
  for ( string group : groups ) {
    for ( string clas : classes ) {
      for ( pair<int, int> time : times ) {
	if ( ongoing[clas][time] == false && lessons[group][time] == "" && taken[clas][group] == false ) {
	  lessons[group][time] = clas;
	  ongoing[clas][time] = true;
	  taken[clas][group] = true;
	}
      }
    }
  }
  for ( string group : groups ) {
    cout << group << endl;
    for ( pair<int, int> time : times ) {
      cout << time.first << ":" << time.second << "    " << lessons[group][time] << endl;
    }
  }
}
