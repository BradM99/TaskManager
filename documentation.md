
**Class Methods**
|--------|
|[TaskManager Class](#TaskManager-Class)|


## Test Plan

### **TaskManager Class**
#### **Private**
|Member Variable|Use|
|----|-----|
|vector<Task> tasks;|Array of task objects to store each task|
|bool calledByRemoveTask| Global Variable to use as a flag for a specific function to track if it was called via another certain function|

#### **Public:**
|Function|Function parameters|Return Type|Expected Outcome|
|----|------|-------|---------|
|**addTask**|String title, string desc, string duedate, bool isComplete|void|Task added to list of tasks|
|**removeTask**|N/A|void|Uses viewTasks(), with option for more info, user can input number to delete that specific task|
|**viewTasks**|N/A|void|Prints list of all task names along with int to ID each <br> Has option to expand on information on each task
|**expandTasks**|N/A|void|Prints list of tasks including their desc, duedate and if theyre completed|

#### More functions are yet to be added once I get more time to finish documentation

