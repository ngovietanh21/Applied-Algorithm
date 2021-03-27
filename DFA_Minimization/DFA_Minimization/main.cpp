// 
//  main.cpp
//  DFA_Minimization
//
//  Created by Viet Anh on 3/29/20.
//  Copyright © 2020 VietAnh. All rights reserved.
//

#define MAX 100
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdio.h>
#include "DisjointSet.cpp"

using namespace std;

// Input data
int numberOfStates, numberOfSymbols, numberOfFinalStates;
bool isFinalStates[MAX];
vector<int>transitionTable[MAX];

// Variables
set<int> reachableStates;
set<int> finalStates;
set<int> states;
vector<set<int>> combineStates;

// Data structures for remove dead states
int path[MAX];
bool visited[MAX];

// Data structures for minimizeDFA -- Myhill Nerode Theorem - Table Filling Method
vector<int> tableFilling[MAX];
bool marked[MAX][MAX];

void input() {
    cin >> numberOfStates >> numberOfSymbols >> numberOfFinalStates;
    
    for (int i = 0; i < numberOfFinalStates; ++i) {
        int state;
        cin >> state;
        isFinalStates[state] = true;
        finalStates.insert(state);
        states.insert(state);
    }
    
    for(int i=0; i<numberOfStates; i++) {
        for(int j=0; j<numberOfSymbols; j++) {
            int state;
            cin >> state;
            transitionTable[i].push_back(state);
        }
    }
}

void findPath(int u, int k) {
    for (int v : transitionTable[u]) {
        if (isFinalStates[v]) {
            for (int i = 1; i<numberOfStates; i++) {
                reachableStates.insert(path[i]);
                states.insert(path[i]);
            }
            break;
        }
        if (!visited[v]) {
            path[k] = v;
            visited[v] = true;
            findPath(v,k+1);
            visited[v] = false;
        }
    }
}

void removeDeadStates() {
    findPath(0,1);
}

bool check(int state1, int state2) {
    
    if (reachableStates.find(state1) != reachableStates.end() &&
        reachableStates.find(state2) != reachableStates.end()) {
        return false;
    }
    
    if (finalStates.find(state1) != finalStates.end() &&
        finalStates.find(state2) != finalStates.end()) {
        return false;
    }
    return true;
}

void printTableFilling() {
    cout << "-------------Table Filling--------------"<<endl;
    cout << "\t";
    for (int state : states) cout << state << "\t";
    cout << endl;
    
    for (int state : states) {
        cout << state << "\t";
        for (int i = 0; i<tableFilling[state].size(); i++) {
            cout << tableFilling[state][i] << "\t";
            
        }
        cout << endl;
    }
}

void printNewDFA() {
    cout << "-------------new DFA--------------" << endl;
    
    for (set<int> setState : combineStates) {
        cout << "(";
        string space = "      ";
        for (int state : setState) {
            cout << state;
            space.pop_back();
            
        }
        cout << ")" << space;
        
        for (int symbol = 0; symbol < numberOfSymbols; symbol++) {
            int transitionState = -1;
            for (int state : setState) {
                int transition = transitionTable[state][symbol];
                if (transitionState != transition) {
                    transitionState = transition;
                }
            }
            cout << transitionState << "\t";
        }
        
        cout << endl;
    }
    
}

void minimizeDFA() {
    //Mark all pairs where P is a final state and Q is not a final state.
    for (set<int>::iterator state1 = states.begin(); state1 != states.end(); state1++) {
        for (set<int>::iterator state2 = states.begin(); state2 != state1; state2++) {
            if (check(*state1, *state2)) {
                tableFilling[*state1].push_back(1);
                marked[*state1][*state2] = true;
            } else {
                tableFilling[*state1].push_back(0);
                marked[*state1][*state2] = false;
            }
        }
    }
    
    //If there are any unmarked pairs such that [delta(P,x), delta(Q,x)] is marked, then mark (P,Q)
    int inter = (int)states.size()/2;
    while (inter) {
        inter--;
        for (set<int>::iterator state1 = states.begin(); state1 != states.end(); state1++) {
            for (set<int>::iterator state2 = states.begin(); state2 != state1; state2++) {
                if (!marked[*state1][*state2]) {
                    for (int symbol = 0; symbol < numberOfSymbols; symbol++) {
                        int transition1 = transitionTable[*state1][symbol];
                        int transition2 = transitionTable[*state2][symbol];
                        
                        if (transition1 < transition2) {
                            if (marked[transition2][transition1]) {
                                tableFilling[*state1][*state2] = 1;
                                marked[*state1][*state2] = true;
                            }
                            
                        } else {
                            if (marked[transition1][transition2]) {
                                tableFilling[*state1][*state2] = 1;
                                marked[*state1][*state2] = true;
                            }
                        }
                    }
                    
                }
                
            }
        }
    }
}

void groupStates() {
    DisjointSet disjointSet (numberOfStates, states);
    
    for (set<int>::iterator state1 = states.begin(); state1 != states.end(); state1++) {
        for (set<int>::iterator state2 = states.begin(); state2 != state1; state2++) {
            if (!marked[*state1][*state2]) {
                disjointSet.join(*state1, *state2);
            }
        }
    }
    
    disjointSet.checkCombineState();
    combineStates = disjointSet.combineStates;
}

int main(){
    freopen("input.txt", "r", stdin);
    input();
    removeDeadStates();
    minimizeDFA();
    printTableFilling();
    groupStates();
    printNewDFA();
    return 0;
}
