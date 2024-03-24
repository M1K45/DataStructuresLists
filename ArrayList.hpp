
#include <iostream>
#include <cstring>

class ArrayList
{
private:
	unsigned size_;
	unsigned capacity_;
	int *array_;

public:

	ArrayList(unsigned capacity);
	ArrayList();
	~ArrayList();

	void doubleSize();

	void removeLastElement(); 

	void addBeginning(int element);

	void addRandom(int element);

	void addEnd(int element);

	void removeBeginning();

	void removeRandom();

	void removeEnd();

	void searchElement(int element) const;

	int displaySize() const;

	int at(int index) const;

};


ArrayList::ArrayList(unsigned capacity): size_{0}, capacity_{capacity}, array_{nullptr}
{
	array_ = new int[capacity_];
}

ArrayList::ArrayList() : size_{ 0 }, capacity_{ 5 }, array_{ nullptr }
{
	array_ = new int[capacity_];
}

ArrayList::~ArrayList()
{
	if (array_ != nullptr) {
		delete[] array_;
		array_ = nullptr;
	}
}

void ArrayList::doubleSize() {
	capacity_ *=2;
	int *tempArray = new int [capacity_]; 
	std::memcpy(tempArray, array_, sizeof(int) * size_);	
	delete[] array_;
	array_ = tempArray;
}

void ArrayList::removeLastElement(){
	int *tempArray = new int [capacity_];
	std::memcpy(tempArray, array_, sizeof(int) * (size_ -1));
    delete[] array_;
	array_ = tempArray;

}


void ArrayList::addBeginning(int element) {
	if (size_ == capacity_) doubleSize();
	for (int i=size_-1; i>= 0; i--){
		array_[i+1] = array_[i];
	}
	array_[0] = element;
	size_++;
}

void ArrayList::addRandom(int element) {
	if (size_ == capacity_) doubleSize();
	int index = rand() %size_;
	while (index == 0 && index == size_-1) index = rand() %size_; // losuje do skutku, aż wybrany zostanie indeks, który nie jest pierwszy, ani ostatni
		for (int i=size_-1; i>= index; i--){
		array_[i+1] = array_[i];
	}
	array_[index] = element;
	size_++;
}

void ArrayList::addEnd(int element) {
	if (size_  == capacity_) doubleSize();
	array_[size_] = element;
	size_++;
}

void ArrayList::removeBeginning() {
	for (int i=1; i<size_; i++) array_[i-1] = array_[i];
	removeLastElement();
	size_ --;
}

void ArrayList::removeRandom() {
	int index = rand() %size_;
	while (index == 0 && index == size_-1) index = rand() %size_; // losuje do skutku, aż wybrany zostanie indeks, który nie jest pierwszy, ani ostatni
		for (int i= index+1; i<size_; i++){
		array_[i-1] = array_[i];
	}
	removeLastElement();
	size_--;
}

void ArrayList::removeEnd() {
	removeLastElement();
	size_ --;

}

void ArrayList::searchElement(int element) const {
	for (int i = 0; i < size_; i++) {
		if (array_[i] == element) {
			std::cout << "\nelement " << element << " was found at index: " << i << std::endl;
			return;
		}
	}
	std::cout << "\nno element \"" << element << "\" found\n";
	return;
}

int ArrayList::displaySize() const{
	return size_;
}

int ArrayList::at(int index) const{
	return array_[index];
}
