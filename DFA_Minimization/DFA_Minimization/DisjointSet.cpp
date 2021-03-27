//
//  DisjointSet.cpp
//  DFA_Minimization
//
//  Created by Viet Anh on 4/1/20.
//  Copyright © 2020 VietAnh. All rights reserved.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class DisjointSet {
private:
    int *rank, *parent, n;
    set<int> states;
    bool *added;
public:
    vector<set<int>> combineStates;
        
    DisjointSet (int n, set<int> &states) {
        rank = new int[n];
        parent = new int[n];
        added = new bool[n];
        this->n = n;
        this->states = states;
        makeSet();
    }
    
    void makeSet() {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
            added[i] = false;
        }
    }
    
    void checkCombineState() {
        for (int state : states) {
            if (!added[state]) {
                if (parent[state] == state) {
                    set<int> newSet ;
                    newSet.insert(state);
                    added[state] = true;
                    combineStates.push_back(newSet);
                } else {
                    findAllChildren(parent[state]);
                }
            }
        }
    }
    
    void findAllChildren(int ofParent){
        set<int> newSet;
        for (int i = 0; i<n; i++) {
            if (parent[i] == ofParent) {
                newSet.insert(i);
                added[i] = true;
            }
        }
        combineStates.push_back(newSet);
    }
    
    int find(int x){
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
     
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] == rank[v]) rank[u]++;
        if (rank[u] < rank[v]) parent[u] = v;
        else parent[v] = u;
    }
};
