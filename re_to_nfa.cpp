#include <iostream>

enum NodeType {
  CHARACTER,
  CONCATENATION,
  UNION,
  KLEENE
};

class ExpressionTree {
  public:
    NodeType type;
    char value;
    struct ExpressionTree * left;
    struct ExpressionTree * right;

    ExpressionTree(NodeType t) {
      type = t;
      left = NULL;
      right = NULL;
    }
};

struct Transition {
  char symbol;
  std::vector<struct NFA_State *> destinationStates;
}

struct NFA_State {
  std::vector<struct Transition> transitions;
}

struct NFA {
  struct NFA_State * startingState;
  struct NFA_State * endingState;
}

struct NFA * eval(ExpressionTree *);
struct NFA * eval_char(ExpressionTree *);
struct NFA * eval_concat(ExpressionTree *);
struct NFA * eval_union(ExpressionTree *);
struct NFA * eval_kleene(ExpressionTree *);

struct NFA * eval(ExpressionTree * root) {
  switch(root->type) {
    case CHARACTER:
      return eval_char(root);
      break;
    case CONCATENATION:
      return eval_concat(root);
    case UNION:
      return eval_union(root);
    case KLEENES:
      return eval_kleens(root);
  }
}

struct NFA * eval_char(ExpressionTree * root) {
  struct NFA * nfa = new struct NFA;
  nfa->startingState = new struct NFA_State;
  nfa->endingState = new struct NFA_State;

  struct Transition t;
  t.symbol = root->value;
  t.destinationStates.push_back(nfa->endingState);

  nfa->startingState->transitions.push_back(t);

  return nfa;
}

struct NFA * eval_concat(ExpressionTree * root) {
  struct NFA * left_nfa = eval(root->left);
  struct NFA * right_nfa = eval(root->right);

  Transition t;
  t.symbol

  left_nfa->endingState->transitions.push_back(t);
}




struct ExpressionTree * createTree() {
  ExpressionTree * a = new ExpressionTree(CHARACTER);
  ExpressionTree * b = new ExpressionTree(CHARACTER);
  ExpressionTree * plus = new ExpressionTree(UNION);

  a->value = 'a';
  b->value = 'b';

  plus->left = a;
  plus->right = b;

  return plus;
}

int main() {
  struct ExpressionTree* root = createTree();
  cout << root << endl;
  return 0;
}
