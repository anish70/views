typedef struct sNaryNode{
	void * data;
	int nChildren;
	struct sNaryNode **children;
}NaryNode;
typedef NaryNode NaryTree;

NaryTree * createNode (int children, void * data){
	NaryNode * node = (NaryNode * )malloc(sizeof(NaryNode));
	node->data = data;
	node->nChildren  = children;
	node->children  = (NaryNode **) malloc(children * sizeof(NaryNode *));
 
	return node;
}


void * createRecord(int id, char name[], ROLE role, int mgr_id){
	employee * record  = (employee *)malloc(sizeof(employee));
	record->id = id;
	strcpy(record->name, name);
	record->role = role;
	record->mgr_id = mgr_id;
 
	return record;
}

typedef void * (DataFreeFunc)(const void *);
 
void freeTree(NaryTree * tree, DataFreeFunc dFree){
 
    unsigned i ;
    //If tree node is NULL, return.
    if ( tree == NULL) return ;
    // Else first recursively delete all children of this node
    for(i=0; i<tree->nChildren; ++i){
    	freeTree(tree->children[i], dFree);
    }
    //Once all childrend are deleted, free up this children array
    free(tree->children);
    
    // This is if you want to deallocate the memory allocated to records too
    if(dFree) dFree(tree->data); 

    //Finally delete the node itself
    free(tree);
}

void addChild(int mgr_id, NaryNode * node){
 
	NaryNode * parent  = hash[mgr_id];
 
	parent->nChildren++;
 
	parent->children = (NaryNode **) realloc(parent->children, parent->nChildren * sizeof(NaryNode *));
	parent->children[parent->nChildren-1] = node;
}


void printTree(NaryNode * tree){
	queue <Node *> q;
	//Push the first node
	q.push(tree);
 	// Now repeat till queue is not empty
	while(!q.empty()){
		Node * temp = q.front();
		q.pop();
		print_data(temp->data);
		int it;
		// Once the node is visited, put all its child on to queue
		for(it = 0; it != temp->nChildren; it++){
			q.push(temp->children[it]);
		}
	}
}


