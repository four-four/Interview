#pragma once
#include <iostream>

struct ArcNode {
    int adjvex;
    ArcNode *next;
};

template <class T> 
struct VertexNode {
    T vertex;
    ArcNode *firstEdge;    
};

const int queueSize = 100;
template <class T>
class queue {
public:
    T data[queueSize];
    int front, rear;
};