#include<iostream>
using namespace std;

//node struct represent a vertex in a graph
struct node {
	int city_name;
	bool air_status;
	node* next;

	//constructor
	node(int c, int a) {
		city_name = c;
		air_status = a;
		next = nullptr;
	}
};

//queue
struct Queue {
	node* head;

	//constructor
	Queue() {
		head = nullptr;
	}

	//push function
	void push(int e) {
		//create node
		node* temp = new node(e, 0);
		node* curr = head;
		//check if queue is empty or not
		if (curr == nullptr) {
			head = temp;
		}
		else {
			while (curr->next) {
				curr = curr->next;
			}
			curr->next = temp;
		}
	}

	//pop function
	void pop() {
		if (!isempty()) {
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	//peek function
	int peek() {
		if (!isempty()) {
			return head->city_name;
		}
		return -1;
	}

	//empty function
	bool isempty() {
		if (head == nullptr) {
			return 1;
		}
		return 0;
	}

	//destructor
	~Queue() {
		while (!isempty()) {
			pop();
		}
	}
};

//reverse queue
void reverse_queue(Queue& result) {
	if (result.isempty()) {
		return;
	}
	int temp = result.peek();
	result.pop();
	reverse_queue(result);
	result.push(temp);
}

//struct graph 
struct Graph {
	//N=number of cities
	int N;
	node** links;

	//constructor
	Graph(int n) {
		N = n;
		//allocating heap memory
		links = new node * [N];
		int i = 0;
		//setting pointers to nullptr and at same time linking cities by road
		while (i < N) {
			links[i] = nullptr;
			if (i != (N - 1)) {
				add_edge(i, i + 1, 0);
			}
			i++;
		}

	}

	//add edge to graph function
	void add_edge(int from, int to, int a) {
		//creating vertex
		//here (a) is the status of  the link is it by air(1) or not(0)
		node* temp = new node(to, a);

		//adding new node at start of links(list) of the given city(from)
		temp->next = links[from];
		links[from] = temp;
	}

	//BFS and shortest path
	void shortest_path() {

		//declaring visited array and queue
		int visited[N];
		Queue queue;

		//putting all index to zero
		for (int i = 0; i < N; i++) {
			visited[i] = 0;
		}

		//marking first city 1 as true and pushing it in queue
		visited[0] = 1;
		queue.push(0);

		node* curr = nullptr;
		int p = 1;
		while (!queue.isempty()) {

			p = queue.peek() + 1;
			queue.pop();
			curr = links[p - 1];
			while (curr) {
				if (!visited[curr->city_name]) {
					visited[curr->city_name] = p;
					queue.push(curr->city_name);
				}
				curr = curr->next;
			}

		}
		output(visited);
	}

	//print the graph
	void print() {
		node* curr = nullptr;

		//for loop control links array
		for (int i = 0; i < N; i++) {

			//pointing curr to first node in linklist of a city(i)
			curr = links[i];
			if (curr) {
				cout << "City " << i + 1 << " linked to: ";
				//here while loop control the list of each city
				while (curr) {

					cout << curr->city_name + 1;
					if (curr->air_status) {
						cout << "(air)";
					}
					else {
						cout << "(road)";
					}

					curr = curr->next;
					if (curr) {
						cout << " , ";
					}
				}
				cout << endl;
			}
			else {
				cout << "City " << i + 1 << " linked to: nothing";
			}
			curr = nullptr;
		}
	}

	//graph destructor
	~Graph() {

		node* temp = nullptr;
		node* curr = nullptr;

		//for loop control links(array)
		for (int i = 0; i < N; i++) {
			curr = links[i];
			//while control node links(list)
			while (curr) {
				temp = curr;
				//delete node at start of list
				curr = curr->next;
				delete temp;
			}
		}
		//delete array(links)
		delete[]links;
	}

	//output generation
	void output(int arr[]) {
		//vriables declare
		int index = 0, number = 0;
		index = N - 1;
		//result queue store shortest path
		Queue result;
		Queue result2;
		string final_result = "";

		//while loop untill start city 1 reached, generate result in reverse order
		while (1) {
			//loop exit when index reached 0
			if (arr[index] == 1 && index == 0) {
				result.push(index + 1);
				result2.push(index + 1);
				break;
			}
			number = arr[index] - 1;
			result.push(index + 1);
			result2.push(index + 1);
			index = number;
		}

		//reversing queue to get correct output
		reverse_queue(result);
		reverse_queue(result2);

		//cities_count and air_count to keep track of days, total_days store final days
		int cities_count = 0, air_count = 0, total_days = 0;
		node* curr = nullptr;
		int city_num = 0, city_num2 = 0;

		//loop continue untill queue is empty
		while (!result.isempty()) {

			//first peek top element in city_num from queue then pop it from the queue 
			city_num = result.peek() - 1;
			curr = links[city_num];
			result.pop();

			if (!result.isempty()) {
				//first peek top element in city_num from queue after previous element is poped
				city_num2 = result.peek() - 1;
				//find city_num2 is links of city_num(index)
				while (curr) {
					if (curr->city_name == city_num2) {
						//check status then 
						if (curr->air_status) {
							cities_count = 0;
							total_days += 1;

						}
						else {
							cities_count++;
							if (cities_count == 5) {
								cities_count = 0;
								total_days += 1;
							}
						}
					}
					curr = curr->next;
				}
			}

		}

		//calculate total_days and then display them
		if (cities_count > 3) {
			total_days += 1;
		}
		cout << "Days = " << total_days << endl;


		//bonus display names of cities
		cout << "Bonus (Displaying shortest path by name):" << endl;
		while (!result2.isempty()) {
			cout << result2.peek() << " ";
			result2.pop();
		}
	}

};

//convert function convert string to int
void convert(string input, int numbers[]) {

	int num = 0;
	//j for array index
	int j = 0;

	//for loop till end of string
	for (int i = 0; input[i] != '\0'; i++) {
		//if space comes it will store it in a array other wise calculate the number befor space
		if (input[i] != ' ') {
			num = (num * 10) + (input[i] - '0');
		}
		else {
			if (j < 2) {
				numbers[j] = num;
				j++;
			}
			num = 0;
		}
	}
	//store last number in an array
	if (j < 2) {
		numbers[j] = num;
	}
}

//valid_input checks if input given is valid or not
bool valid_input(string input, int spaces) {

	bool valid = 1;
	char check;
	int count_space = 0;

	for (int i = 0; input[i] != '\0'; i++) {

		//checks for spaces
		if (input[i] == ' ') {
			count_space++;
			if ((count_space > spaces)) {
				cout << "Only enter numbers as needed" << endl;
				valid = 0;
				break;
			}
		}

		//check for only numbers in the string or not
		if ((input[i] >= '0' && input[i] <= '9') || (input[i] == ' ')) {

		}
		else
		{
			if (input[i] == '-' || input[i] == '+' || input[i] == '*' || input[i] == '/') {
				cout << "do not enter any operator" << endl;
			}
			else {
				cout << "Only enter numbers" << endl;
			}
			valid = 0;
			break;
		}
	}

	if ((count_space < spaces)) {
		cout << "Only enter numbers as needed" << endl;
		valid = 0;
	}

	return valid;
}

//case_solve solve each test case graph
void case_solve(string input, int number[]) {
	//aerial_routes stores max number of air roots in graph, N stores max city number
	int aerial_routes = 0;
	int N = 0;
	int again = 1, i = 0;

	//loops to again ask for input after invalid previous input
	while (again) {
		input = "";
		//taking input for number of max cities(N)
		cout << "Enter number of cities = ";
		getline(cin, input);

		if (valid_input(input, 0)) {
			convert(input, number);
			N = number[0];
			if (N) {
				while (again) {
					input = "";
					number[0] = 0;
					number[1] = 0;
					//taking input for total number of aerial_rootes in the graph
					cout << "Enter number of aerial_rootes = ";
					getline(cin, input);

					if (valid_input(input, 0)) {
						convert(input, number);
						aerial_routes = number[0];
						input = "";
						number[0] = 0;
						number[1] = 0;
						again = 0;
					}
				}
			}
			else {
				cout << "Enter number of cities greater than 0" << endl;
			}
		}
	}

	again = 1;
	//making graph cantaining cities(N)
	Graph graph(N);

	//loops to again ask for input after invalid previous input
	while (again) {
		if (i < aerial_routes) {
			//taking input for cities air root
			getline(cin, input);
			if (valid_input(input, 1)) {
				convert(input, number);
				if ((number[0] <= (N) && number[0] > 0) && (number[1] <= (N) && number[1] > 0) && (number[0] != number[1])) {
					graph.add_edge(number[0] - 1, number[1] - 1, 1);
					i++;
				}
				else if (number[0] == number[1]) {
					cout << "Source and destination city can not be same" << endl;
				}
				else {
					cout << "Enter number greater then zero or less then " << N << endl;
				}
				input = "";
				number[0] = 0;
				number[1] = 0;
			}
		}
		else {
			again = 0;
		}
	}


	graph.shortest_path();
}

int main() {


	//number array used to store numbers when convert from string to int
	int number[] = { 0,0 };
	string input = "";

	//enter number of cases
	int cases = 0;
	while (1) {
		cout << "Enter number of Test cases = ";
		getline(cin, input);
		if (valid_input(input, 0)) {
			//convert string to int
			convert(input, number);
			if (number[0] != 0) {
				cases = number[0];
				break;
			}
			else {
				cout << "Enter number greater then zero" << endl;
			}
		}
	}



	//call case_solve function for number of cases
	for (int i = 0; i < cases; i++) {
		input = "";
		number[0] = 0;
		number[1] = 0;
		//calling case_solve function
		cout << "Test case " << i + 1 << endl;
		case_solve(input, number);
		cout << endl;
	}

	return 0;
}