#include <string>
#include <fstream>

#include "QueType.h"
#include "CarType.h"

#define INPUT_FILE "autodata.txt"
#define OUTPUT_FILE "results.txt"

struct TreeNode {
    CarType info;
    TreeNode* left;
    TreeNode* right;
};

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
    
    /**
     * fills the tree with data from input file
     */
    void initialize();
    
    /**
     * When the show command is calls it prints to the command line and to the
     * output file
     * @param outFile
     */
    void showCommand(std::ofstream& outFile) const;
    
    /**
     * checks to see if a car is in the search list
     * @param carName
     */
    void checkAuto(std::string carName);
    
    /**
     * filters the search list if the car has the feature
     * @param feature
     */
    void hasFeature(std::string feature);
    
    /**
     * returns the root tree node
     * @return 
     */
    TreeNode* getRoot();
    
    /**
     * iterates through list to see if a car name exists
     * @param carName
     * @return 
     */
    bool doesCarExist(const std::string carName);
    
private:
    
    /**
     * reads from the input file
     */
    void readFromCSV();
    
    TreeNode* root;
    QueType preQue;
    QueType inQue;
    QueType postQue;
    OrderType currentOrder;
};

