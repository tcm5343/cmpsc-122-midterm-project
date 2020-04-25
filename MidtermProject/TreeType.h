#include <string>
#include <fstream>

#include "QueType.h"
#include "CarType.h"

#define INPUT_FILE "autodata.txt"
#define OUTPUT_FILE "results.txt"

struct TreeNode;

enum OrderType {
    PRE_ORDER, IN_ORDER, POST_ORDER
};

class TreeType {
public:
    TreeType(); // constructor
    ~TreeType(); // destructor
    TreeType(const TreeType& originalTree);
    void operator=(const TreeType& originalTree);
    // copy constructor
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    int GetLength() const;
    CarType GetItem(CarType item, bool& found);
    void PutItem(CarType item);
    void DeleteItem(CarType item);
    void ResetTree(OrderType order);
    CarType GetNextItem(OrderType order, bool& finished);
    void Print(std::ofstream& outFile) const;
    void initialize();
    void showCommand(std::ofstream& outFile) const;
    void checkAuto(std::string carName);
    void hasFeature(std::string feature, std::vector<CarType>& featurlessCars);
private:
    void readFromCSV();
    TreeNode* root;
    QueType preQue;
    QueType inQue;
    QueType postQue;
    OrderType currentOrder;
};

