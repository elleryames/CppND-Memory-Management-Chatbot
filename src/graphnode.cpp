#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // Note: _chatBot is allocated and deleted within chatlogic ctor/dtor.
    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// Task 4: implement move semantics that allow node to own its child edges.
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge>&& edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
// Task 5: ownership is passed b/c this triggers use of ChatBot move constructor.
void GraphNode::MoveChatbotHere(ChatBot chatbot) 
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode* newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot)); // Task 5
    //_chatBot = nullptr; // invalidate pointer at source // Task 5 _chatBot changed to object rather than pointer. 
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get(); // Task 4

    ////
    //// EOF STUDENT CODE
}