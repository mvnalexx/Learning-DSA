#include <bits/stdc++.h>
using namespace std;

struct Node { // struct используем всегда для создания Node 
    int data; // the data stored in the Node добавляем валью
    Node* next; // the pointer to the next Node создаем поинтер на следующий ноуд
    
    Node(int value) { // Constructor to initialize the next Node создвем конструктор для того чтобы давать данные
        data=value; // присваимваем валью дате
        next = nullptr; // Initialize pointer to null направляем поинтер на ноль, некий тэил который всегда ноль чтобы видеть конец нашего листа
    }
}; // закрываем стракт всегда ; иначе ошибка будет

Node* head = nullptr; // присваиваем хэду ноль, т.к. у нас сначала пустой лист, поэтому и начало(хэд) и конец(тэил) у нас ноль

void insertAtHead(int value) { // создаем первую функцию чтобы добавить новый ноуд на позицию хэда
    // create new Node
    Node* newNode = new Node(value); // создаем тот самый новый ноуд через newNode = new Node(value); 
    // make new Node connected point to the current Head
    newNode->next = head; // коннектим новый ноут к прошлому хэду, тем самым ставив новый ноуд на первое место, а хэд(ноль) двигается вправо и становится обычным ноудом, а новый ноуд становится хэдом
    //connect the head to the new Node
    head = newNode; // ну и теперь последний шаг присваиваем переменной хэд значение нашего нового нода и тем самым завершаем вставку нового ноуда на позицию хэда
}

void printList() { // функция печати нашего листа
    Node* temp = head;// use a temporary pointer to traverse the list создаем временный поинтер чтобы перевернуть лист и присваиваем ему хэд чтобы начать с начала и дойти до конца листа
    cout <<"Linked List: "; 
    while (temp!=nullptr) { // пока временный поинтер не дойдет до тэила, т.е. конца
        cout <<temp->data << " -> "; // печатаем значение временного ноуда
        temp=temp->next; // move to the next node // присваиваем нашему временному ноуду следующий ноуд чтобы при повторе печатать уже второй элемент списка и так далее
    }
    cout << "NULL" << endl; // наш цикл закончится когда дойдем до нуля поэтому надо вручную ноль печатать и теперь лист официально полностью запринтен
}

void insertAtTheEnd (int value) { // еще одна функция, теперь у нас добавляем ноуд с конца как раз перед тэилом. Т.е. по логике мы создаем новый ноуд, проверяем условие что лист не пустой. 
    Node* newNode = new Node(value);
    if (head==nullptr) {
        head=newNode;
        return;
    }
    // потом после проверки создаем временный поинтер и назначаем ему значение хэда, ранем пока поинтер нашего поинтера не равен нулю, т.е. раним до последнего ноуда, которыц стоит до тэила. 
    Node* temp = head;
    while (temp->next!=nullptr) {
        temp=temp->next;
    }
    temp->next = newNode; // ну доранили мы до последнего элемента, теперь просто пишем что поинтер последнего ноуда указывает на новый ноуд, а новый ноуд автоматически уже на ноль указывает что-ли? странно... надо перепрроверить это. На сегодня пока все. Вернись сюда 11го октября хотя бы не надолго.
}

void deleteNode (int value) {  
    if (head==nullptr) {  
        cout << "The list is empty";
        return;
    }
    if (head->data==value) { // короче мы тут тоже используем временную переменную как буфер. Т.е. мы даем присваиваем тэмпу хэд, а хэд меняем на следующий ноуд. потом удаляем темп и тем самым удаляем ноуд из списка. 
        Node* temp = head;
        head=head->next;
        delete temp;
        return;
    }
    Node* current = head; // если удаляем не хэд, а где то в середиине, то создаем каррент и ему присваиаем хэд. потом создаем прив и даем ему ноль.
    Node* prev = nullptr;
    
    while (current!= nullptr and current->data!=value) { // теперь гоним цикл пока каррент не ноль и пока каррент значение не ровно тому которое мы должны удалить мы пишем что предудющий теперь равен каренту, а карент равен следующему карента.
        prev=current;
        current=current->next;
    }
    
    if (current==nullptr) { // если кареннт равен нулю после того, что мы сделали значит значения нет в листе и мы говорим им об этом.
        cout <<"Value " << value << " not found in the list" << endl;
        return;
    }
    
    prev->next=current->next; // когда мы нашли нужное значение, мы прошлое от него теперь поинтим на его следующее чтобы связь продолжалась и потом удаляем этот ноуд чтобы избавиться от узла (кареннта).
    delete current;
}

void insertAfterNode(Node* prevNode, int value) { // вот этот совсем не сложный, также проверяем лист. если прошлый ноуд - ноль, то все уже. 
    if (prevNode == nullptr) {
        cout << "Previous Node cannot be NULL";
        return;
    }
    
    Node* newNode = new Node(value); // если нет, то создаем новый ноуд и поинтим ноуд на тот на который поинтил ноуд перед нами. После делем так чтобы перед нами поинтил на нас.
    newNode->next = prevNode->next;
    prevNode->next=newNode;
}

void insertBeforeNode(Node* nextNode, int value) { // обратная тема. проверяем если следующий ноуд ноль.
    if (nextNode == nullptr) {
        cout << "Next Node cannot be NULL";
        return;
    }
    
    if (nextNode == head) {// если нет и если ноуд перед которым надо вставить это хэд, то просто ранним вставка в хэд.
        insertAtHead(value);
        return;
    }
    // если не хэд, то создаем карэнт равный хэду. ранним цикл пока карент не равен нулю и пока карент не поинтит на этот следующий ноуд перед которым мы должны вставить
    Node* current = head;
    while (current!=nullptr and current->next!=nextNode){
        current->next;
    }
    if (current==nullptr) { // если каррент ноль, то ноуд перед которым вставить не существует.
        cout << "Given Node is not in the list!";
        return;
    }
    // если мы все-таки его нашли, то мы создаем новый ноуд который будет поинтить на этот нэкст ноуд, а каррент будет поинтить на новый ноуд.
    Node* newNode = new Node(value);
    newNode->next = nextNode;
    current->next = newNode;
}

void insertAtPosition(int position, int value) { //так теперь ун ас есть определенная позиция
    if (position < 0) {
        cout << "position cannot be less than 0"; // сразу чекаем на децствительность
        return;
    }
    if (position==0) { // если ноль, то значит хэд
        insertAtHead(value);
        return;
    }
    Node* current = head; // создаем каррент и ранним цикл пока не дойдем до ноуда перед нужным и пока карент не равен нулю
    for (int i=0; i<position-1 and current!=nullptr; i++) {
        current=current->next;
    }
    if (current==nullptr) { // если карент ноль, то позиция за пределами
        cout << "Position " << position << " is out of bounds!" << endl;
        return;
    }
    Node* newNode = new Node(value); // создаем новый ноуд и вставляем его так что он будет поинтить на тот ноуд на позицию которого нам нужно вставить
    newNode->next=current->next;
    current->next=newNode; // ну и теперь тот который стоял паред нужным ноудом будет поинтить на новый
}

int main() {
    // Start with an empty list

    insertAtHead(3); // List: 3 -> NULL
    insertAtHead(2); // List: 2 -> 3 -> NULL
    insertAtHead(1); // List: 1 -> 2 -> 3 -> NULL
    
    insertAtPosition(3, 5);
    
    printList();
    
    deleteNode(1);
    
    printList();
    
    return 0;
}
