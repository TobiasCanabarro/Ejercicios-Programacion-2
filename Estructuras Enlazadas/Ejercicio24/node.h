#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 80




void insertOrderedDiv(NodeSub ** list, int div);

void insertOrderedLegajo(Node ** list, int legajo);

int deleteDiv(NodeSub ** list);

int deleteLegajo(Node ** list);


#endif // NODE_H_INCLUDED
