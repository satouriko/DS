#ifndef DS_2016_GRAPH_H
#define DS_2016_GRAPH_H

enum {
    UNDISCOVERED,
    DISCOVERED,
    VISITED
};
enum {
    UNDETERMINED,
    TREE,
    CROSS,
    FORWARD,
    BACKWARD
};

template <typename Tv, typename Te>
class Graph {
public:
    int n; // 顶点总数
    int e; // 边总数
};

#endif // DS_2016_GRAPH_H
