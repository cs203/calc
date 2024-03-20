#ifndef tree_h
#define tree_h
struct Node
{
	virtual ~Node();
	virtual double Calc() const = 0;
	virtual bool IsLvalue() const;
	virtual void Assign(double num){};
};

struct NumNode: public Node
{
	NumNode(double num);
	double Calc() const override;
private:
	const double _num;
};

struct UMinusNode: public Node
{
	UMinusNode(Node *pNode);
	~UMinusNode();
	double Calc() const override;
private:
	Node * const _pNode;
};

struct Store;

struct VarNode: public Node
{
	VarNode(int id, Store store);
	double Calc() const override;
	bool IsLvalue() const override;
	void Assign(double num) override;
private:
	int const _id;
	Store &_store;
};

#endif
