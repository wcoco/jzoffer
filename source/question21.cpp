#include <iostream>
#include <stack>

/* 包含min函数的栈*/

template<typename T>
class StackWithMin{
public:
	StackWithMin();
	void push(const T& value);
	void pop();
	const T& min() const;
private:
	std::stack<T> m_data;
	std::stack<T> m_min;
};

template<typename T>
void StackWithMin<T>::push(const T& value){
	m_data.push(value);
	if (m_min.size() == 0 || value < m_min.top())   // 默认可比较
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template<typename T>
void StackWithMin<T>::pop(){
	m_data.pop();
	m_min.pop();
}

template<typename T>
const T& StackWithMin<T>::min() const{
	return m_min.top();
}

int main(){



	return 0;
}