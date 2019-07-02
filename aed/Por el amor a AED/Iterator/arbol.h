#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

template<typename T>
struct Less {
	bool operator()(T a, T b) {
		return a < b;
	}
};

template<typename T>
struct Greater{
	bool operator()(T a,T b) {
		return a > b;
	}
};

template<typename T>
struct CNode {
	T m_data;
	CNode<T>* m_nodes[2];
	CNode(T x) {
		m_data = x;
		m_nodes[0] = m_nodes[1] = NULL;
	}
};

template <typename T>
struct CITreeIn {
	stack<pair<CNode<T>*,int> > m_pila;
	CNode<T> *m_value;
	CITreeIn(CNode<T> * m_r = NULL) {
		pair<CNode<T>*, int> m_pair;
		if (!!m_r) {
			m_pair.first = m_r;
			m_pair.second = 0;
			m_pila.push(m_pair);
			while (m_r->m_nodes[0]) {
				m_pair.first = m_r->m_nodes[0];
				m_pair.second = 0;
				m_pila.push(m_pair);
				m_r = m_r->m_nodes[0];
			}
			m_pair = m_pila.top();
			m_pair.second = 2;
			m_pila.pop();
			m_pila.push(m_pair);
		}
		m_value = m_pair.first;
	}
	CITreeIn operator=(CITreeIn m) {
		stack<pair<CNode<T>*, int> > m_aux;
		while (!m.m_pila.empty()) {
			m_aux.push(m.m_pila.top());
			m.m_pila.pop();
		}
		while (!m_aux.empty()) {
			m_pila.push(m_aux.top());
			m_aux.pop();
		}
		m_value = m.m_value;
		return *this;
	}
	bool operator!=(CITreeIn j) {
		if (j.m_pila.size() != m_pila.size()) return true;
		if (j.m_pila.empty() && m_pila.empty()) {
			return false;
		}
		stack<pair<CNode<T>*, int> > aux1 = m_pila;
		stack<pair<CNode<T>*, int> > aux2 = j.m_pila;
		while (!aux1.empty()) {
			pair<CNode<T>*, int> m_pair = aux1.top();
			pair<CNode<T>*, int> m_jpair = aux2.top();
			if ((m_pair.first != m_jpair.first) )
				return true;
			else {
				aux1.pop(); aux2.pop();
			}
		}
		return false;
	}
	CITreeIn operator++(int a){
		pair<CNode<T>*, int> m_pair;
		m_pair = m_pila.top();
		while ( m_pila.size() >= 1 && m_pair.second != 1) {
			CNode<T> * m_nexo = m_pair.first;
			switch (m_pair.second){
			case 0:
				if (m_nexo->m_nodes[0]) {
					pair<CNode<T>*, int> m_aux;
					m_aux.first = m_nexo->m_nodes[0];
					m_aux.second = 0;
					m_pila.push(m_aux);
				}
				else {
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			case 2:
				if (m_nexo->m_nodes[1]) {
					pair<CNode<T>*, int> m_aux;
					m_aux.first = m_nexo->m_nodes[1];
					m_aux.second = 0;
					m_pila.push(m_aux);
				}
				else {
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			case 3:
				m_pila.pop();
				if (!m_pila.empty()) {
					m_pair = m_pila.top();
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			default:
				break;
			}
			if (!m_pila.empty())
				m_pair = m_pila.top();
			else {
				m_pair.first = NULL;
				m_pair.second = 1;
			}
		}
		if (!m_pila.empty() && m_pair.second < 3) {
			m_value = m_pair.first;
			m_pair.second++;
			m_pila.pop();
			m_pila.push(m_pair);
		}
		else if(!m_pila.empty())
			m_pila.pop();
		return *this;
	}

	T& operator*() {
		return m_value->m_data;
	}
};

template <typename T>
struct CITreeReverse {
	stack<pair<CNode<T>*, int> > m_pila;
	CNode<T> *m_value;
	CITreeReverse(CNode<T> * m_r = NULL) {
		pair<CNode<T>*, int> m_pair;
		if (!!m_r) {
			m_pair.first = m_r;
			m_pair.second = 0;
			m_pila.push(m_pair);
			while (m_r->m_nodes[1]) {
				m_pair.first = m_r->m_nodes[1];
				m_pair.second = 0;
				m_pila.push(m_pair);
				m_r = m_r->m_nodes[1];
			}
			m_pair = m_pila.top();
			m_pair.second = 2;
			m_pila.pop();
			m_pila.push(m_pair);
		}
		m_value = m_pair.first;
	}
	CITreeReverse operator=(CITreeReverse m) {
		stack<pair<CNode<T>*, int> > m_aux;
		while (!m.m_pila.empty()) {
			m_aux.push(m.m_pila.top());
			m.m_pila.pop();
		}
		while (!m_aux.empty()) {
			m_pila.push(m_aux.top());
			m_aux.pop();
		}
		m_value = m.m_value;
		return *this;
	}
	bool operator!=(CITreeReverse j) {
		if (j.m_pila.size() != m_pila.size()) return true;
		if (j.m_pila.empty() && m_pila.empty()) {
			return false;
		}
		stack<pair<CNode<T>*, int> > aux1 = m_pila;
		stack<pair<CNode<T>*, int> > aux2 = j.m_pila;
		while (!aux1.empty()) {
			pair<CNode<T>*, int> m_pair = aux1.top();
			pair<CNode<T>*, int> m_jpair = aux2.top();
			if ((m_pair.first != m_jpair.first))
				return true;
			else {
				aux1.pop(); aux2.pop();
			}
		}
		return false;
	}
	CITreeReverse operator++(int a) {
		pair<CNode<T>*, int> m_pair;
		m_pair = m_pila.top();
		while (m_pila.size() >= 1 && m_pair.second != 1) {
			CNode<T> * m_nexo = m_pair.first;
			switch (m_pair.second) {
			case 0:
				if (m_nexo->m_nodes[1]) {
					pair<CNode<T>*, int> m_aux;
					m_aux.first = m_nexo->m_nodes[1];
					m_aux.second = 0;
					m_pila.push(m_aux);
				}
				else {
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			case 2:
				if (m_nexo->m_nodes[0]) {
					pair<CNode<T>*, int> m_aux;
					m_aux.first = m_nexo->m_nodes[0];
					m_aux.second = 0;
					m_pila.push(m_aux);
				}
				else {
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			case 3:
				m_pila.pop();
				if (!m_pila.empty()) {
					m_pair = m_pila.top();
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			default:
				break;
			}
			if (!m_pila.empty())
				m_pair = m_pila.top();
			else {
				m_pair.first = NULL;
				m_pair.second = 1;
			}
		}
		if (!m_pila.empty() && m_pair.second < 3) {
			m_value = m_pair.first;
			m_pair.second++;
			m_pila.pop();
			m_pila.push(m_pair);
		}
		else if (!m_pila.empty())
			m_pila.pop();
		return *this;
	}

	T& operator*() {
		return m_value->m_data;
	}
};

template <typename T>
struct CITreePost {
	stack<pair<CNode<T>*, int> > m_pila;
	CNode<T> *m_value;
	CITreePost(CNode<T> * m_r = NULL) {
		pair<CNode<T>*, int> m_pair;
		if (!!m_r) {
			m_pair.first = m_r;
			m_pair.second = 0;
			m_pila.push(m_pair);
			while (m_r->m_nodes[0]) {
				m_pair.first = m_r->m_nodes[0];
				m_pair.second = 0;
				m_pila.push(m_pair);
				m_r = m_r->m_nodes[0];
			}
			m_pair = m_pila.top();
			m_pair.second = 3;
			m_pila.pop();
			m_pila.push(m_pair);
		}
		m_value = m_pair.first;
	}
	CITreePost operator=(CITreePost m) {
		stack<pair<CNode<T>*, int> > m_aux;
		while (!m.m_pila.empty()) {
			m_aux.push(m.m_pila.top());
			m.m_pila.pop();
		}
		while (!m_aux.empty()) {
			m_pila.push(m_aux.top());
			m_aux.pop();
		}
		m_value = m.m_value;
		return *this;
	}
	bool operator!=(CITreePost j) {
		if (j.m_pila.size() != m_pila.size()) return true;
		if (j.m_pila.empty() && m_pila.empty()) {
			return false;
		}
		stack<pair<CNode<T>*, int> > aux1 = m_pila;
		stack<pair<CNode<T>*, int> > aux2 = j.m_pila;
		while (!aux1.empty()) {
			pair<CNode<T>*, int> m_pair = aux1.top();
			pair<CNode<T>*, int> m_jpair = aux2.top();
			if ((m_pair.first != m_jpair.first))
				return true;
			else {
				aux1.pop(); aux2.pop();
			}
		}
		return false;
	}
	CITreePost operator++(int a) {
		pair<CNode<T>*, int> m_pair;
		m_pair = m_pila.top();
		while (m_pila.size() >= 1 && m_pair.second != 2) {
			CNode<T> * m_nexo = m_pair.first;
			switch (m_pair.second) {
			case 0:
				if (m_nexo->m_nodes[0]) {
					pair<CNode<T>*, int> m_aux;
					m_aux.first = m_nexo->m_nodes[0];
					m_aux.second = 0;
					m_pila.push(m_aux);
				}
				else {
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			case 1:
				if (m_nexo->m_nodes[1]) {
					pair<CNode<T>*, int> m_aux;
					m_aux.first = m_nexo->m_nodes[1];
					m_aux.second = 0;
					m_pila.push(m_aux);
				}
				else {
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			case 3:
				m_pila.pop();
				if (!m_pila.empty()) {
					m_pair = m_pila.top();
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			default:
				break;
			}
			if (!m_pila.empty())
				m_pair = m_pila.top();
			else {
				m_pair.first = NULL;
				m_pair.second = 0;
			}
		}
		if (!m_pila.empty() && m_pair.second < 3) {
			m_value = m_pair.first;
			m_pair.second++;
			m_pila.pop();
			m_pila.push(m_pair);
		}
		else if (!m_pila.empty())
			m_pila.pop();
		return *this;
	}

	T& operator*() {
		return m_value->m_data;
	}
};

template <typename T>
struct CITreePre {
	stack<pair<CNode<T>*, int> > m_pila;
	CNode<T> *m_value;
	CITreePre(CNode<T> * m_r = NULL) {
		pair<CNode<T>*, int> m_pair;
		if (!!m_r) {
			m_pair.first = m_r;
			m_pair.second = 1;
			m_pila.push(m_pair);
		}
		m_value = m_pair.first;
	}
	CITreePre operator=(CITreePre m) {
		stack<pair<CNode<T>*, int> > m_aux;
		while (!m.m_pila.empty()) {
			m_aux.push(m.m_pila.top());
			m.m_pila.pop();
		}
		while (!m_aux.empty()) {
			m_pila.push(m_aux.top());
			m_aux.pop();
		}
		m_value = m.m_value;
		return *this;
	}
	bool operator!=(CITreePre j) {
		if (j.m_pila.size() != m_pila.size()) return true;
		if (j.m_pila.empty() && m_pila.empty()) {
			return false;
		}
		stack<pair<CNode<T>*, int> > aux1 = m_pila;
		stack<pair<CNode<T>*, int> > aux2 = j.m_pila;
		while (!aux1.empty()) {
			pair<CNode<T>*, int> m_pair = aux1.top();
			pair<CNode<T>*, int> m_jpair = aux2.top();
			if ((m_pair.first != m_jpair.first))
				return true;
			else {
				aux1.pop(); aux2.pop();
			}
		}
		return false;
	}
	CITreePre operator++(int a) {
		pair<CNode<T>*, int> m_pair;
		m_pair = m_pila.top();
		while (m_pila.size() >= 1 && m_pair.second != 0) {
			CNode<T> * m_nexo = m_pair.first;
			switch (m_pair.second) {
			case 1:
				if (m_nexo->m_nodes[0]) {
					pair<CNode<T>*, int> m_aux;
					m_aux.first = m_nexo->m_nodes[0];
					m_aux.second = 0;
					m_pila.push(m_aux);
				}
				else {
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			case 2:
				if (m_nexo->m_nodes[1]) {
					pair<CNode<T>*, int> m_aux;
					m_aux.first = m_nexo->m_nodes[1];
					m_aux.second = 0;
					m_pila.push(m_aux);
				}
				else {
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			case 3:
				m_pila.pop();
				if (!m_pila.empty()) {
					m_pair = m_pila.top();
					m_pair.second++;
					m_pila.pop();
					m_pila.push(m_pair);
				}
				break;
			default:
				break;
			}
			if (!m_pila.empty())
				m_pair = m_pila.top();
			else {
				m_pair.first = NULL;
				m_pair.second = 0;
			}
		}
		if (!m_pila.empty() && m_pair.second < 3) {
			m_value = m_pair.first;
			m_pair.second++;
			m_pila.pop();
			m_pila.push(m_pair);
		}
		else if (!m_pila.empty())
			m_pila.pop();
		return *this;
	}

	T& operator*() {
		return m_value->m_data;
	}
};

template <typename T, class C>
struct CBinaryTree {
	CNode<T> * m_root;
	C m_cmp;
	typedef CITreeIn<T> iteratorInOrder;
	typedef CITreePre<T> iteratorPreOrder;
	typedef CITreePost<T> iteratorPostOrder;
	typedef CITreeReverse<T> iteratorReverse;
	CBinaryTree(){
		m_root = NULL;
	}
	~CBinaryTree() {

	}
	iteratorInOrder beginIn() {
		return iteratorInOrder(m_root);
	}
	iteratorInOrder endIn() {
		return iteratorInOrder(NULL);
	}
	iteratorReverse beginRev() {
		return iteratorReverse(m_root);
	}
	iteratorReverse endRev() {
		return iteratorReverse(NULL);
	}
	iteratorPreOrder beginPre() {
		return iteratorPreOrder(m_root);
	}
	iteratorPreOrder endPre() {
		return iteratorPreOrder(NULL);
	}
	iteratorPostOrder beginPost() {
		return iteratorPostOrder(m_root);
	}
	iteratorPostOrder endPost() {
		return iteratorPostOrder(NULL);
	}
	bool find(T , CNode<T>** &);
	bool insert(T);
	bool remove(T);
	CNode<T> ** rep(CNode<T> **);

	void printNiveles(CNode<T> * p ) {
	    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "\nNiveles del Arbol\n";
		vector <CNode<T>*> c;
		c.push_back(m_root);
		int len;
		while (c.size() != 0) {
			len = c.size();
			for (int i = 0;i < len;i++) {
				if (c[i]) {
                    //SetConsoleTextAttribute(hConsole, 4);
					cout << c[i]->m_data << " ";
					c.push_back(c[i]->m_nodes[0]);
					c.push_back(c[i]->m_nodes[1]);
				}
				else
					cout << "- ";
			}
			cout << endl;
			c.erase(c.begin(), c.begin() + len);
		}

	}

	void printPreOrder(CNode<T>*p ) {
		if (!p) return;
		cout << p->m_data;
		printPreOrder(p->m_nodes[0]);
		printPreOrder(p->m_nodes[1]);
	}
	void printPostOrder(CNode<T> *p) {
		if (!p) return;
		printPostOrder(p->m_nodes[0]);
		printPostOrder(p->m_nodes[1]);
		cout << p->m_data;
	}
	void printIn(CNode<T> *p) {
		if (!p) return;
		printIn(p->m_nodes[0]);
		cout << p->m_data;
		printIn(p->m_nodes[1]);
	}
};

template <typename T, class C>
bool CBinaryTree<T,C>::find(T x, CNode<T> ** & p) {
	p = &m_root;
	while (*p && (*p)->m_data != x){
		p = &((*p)->m_nodes[m_cmp((*p)->m_data, x)]);
	}
	return !!*p;
}

template <typename T, class C>
CNode<T> ** CBinaryTree<T,C>::rep(CNode<T> ** q) {
	q = &(*q)->m_nodes[0];
	while ((*q)->m_nodes[1])
	{
		q = &((*q)->m_nodes[1]);
	}
	return q;
}

template <typename T, class C>
bool CBinaryTree<T, C>::insert(T x) {
	CNode<T> ** m_pointerLink;
	if (find(x, m_pointerLink)) {
		return 0;
	}
	else {
		 *m_pointerLink = new CNode<T>(x);
		return 1;
	}
}

template<typename T, class C>
bool CBinaryTree<T, C>::remove(T x) {
	CNode<T> ** p;
	if (!find(x, p)) return 0;
	if ((*p)->m_nodes[0] && (*p)->m_nodes[1]) {
		CNode<T>** q = rep(p);
		(*p)->m_data = (*q)->m_data;
		p = q;
	}
	CNode<T> * t = *p;
	*p = (*p)->m_nodes[(*p)->m_nodes[0] == NULL];
	delete t;
	return 1;
}



#endif // ARBOL_H_INCLUDED
