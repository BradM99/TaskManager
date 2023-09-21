**Class Methods**
|--------|
|[TaskManager Class](#TaskManager-Class)|
|[Task Class](#Task-Class)|


## Test Plan

### **TaskManager Class**
#### **Private:**
|Member Variable|Use|
|----|-----|
|**vector<Task> tasks**|Array of task objects to store each task|
|**bool calledByRemoveTask**| Global Variable to use as a flag for a specific function to track if it was called via another certain function|

#### **Public:**
|Function|Function parameters|Return Type|Expected Outcome|
|----|------|-------|---------|
|**addTask()**|String title, string desc, string duedate, bool isComplete|void|Task added to list of tasks|
|**removeTask()**|N/A|void|Uses viewTasks(), with option for more info, user can input number to delete that specific task|
|**viewTasks()**|N/A|void|Prints list of all task names along with int to ID each <br> Has option to expand on information on each task
|**expandTasks()**|N/A|void|Prints list of tasks including their desc, duedate and if theyre completed|
|**markComplete()**|N/A|void|Update a task status to complete|
|**updateFile()**|N/A|void|Store all **current** task array information in txt document|
|**loadTasksFromFile()**|const string& filename|void|On startup, read text file to build up array of tasks|
|**whiteSpaceTrim()**|const string& key const string& value|void|Trim leading and trailing whitespace from key and value|

### **Task Class**
#### **Private:**
|Member Variable|Use|
|----|-----|
|**string Title**|Stores name of task as string|
|**string Description**|Stores description of task as string|
|**string DueDate**|Stores Due Date of task as string (**should change to date/time**)|
|**bool isComplete**|Value to check if task has been completed|

#### **Public:**
|Function|Function parameters|Return Type|Expected Outcome|
|----|------|-------|---------|
|**Task() Default Constructor**|N/A|N/A|Create empty Task object|
|**Task()**|string title, string description, string dueDate, bool isComplete|Task|Set object members with parameters passed to function|
|**getTitle()**|N/A|string|return the title member of a Task object|
|**setTitle()**|string title|N/A|Set task object title as passed string|
|**getDescription()**|N/A|string|return the description member of a Task object|
|**setDescription()**|string description|N/A|Set task object description as passed string|
|**getDueDate()**|N/A|string|return the DueDate member of a Task object|
|**setDueDate()**|string dueDate|N/A|Set task object DueDate as passed string|
|**getIsComplete()**|N/A|bool|return the isComplete member of a Task object|
|**setIsComplete()**|bool newIsComplete|N/A|Set task object isComplete as passed bool|


#### More methods are yet to be added once I get more time to finish documentation

