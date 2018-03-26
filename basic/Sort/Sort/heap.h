#pragma once
#include <vector>

// MAX HEAP
class Heap {
private:
	int	m_size;
	int	m_maxSize;
	std::vector<int> m_buffer;

	void Swap(int i, int j) {
		int temp = m_buffer[i];
		m_buffer[i] = m_buffer[j];
		m_buffer[j] = temp;
	}

public:
	Heap(int _maxSize) {
		m_size = 0;
		m_maxSize = _maxSize;
		m_buffer.assign(_maxSize, 0);
	}

	bool isEmpty() {
		return m_size == 0;
	}

	bool isFull() {
		return m_size == m_maxSize;
	}

	void PrintHeap(int _size) {
		for (int i = 0; i < _size; i++) {
			std::cout << m_buffer[i] << " ";
		}
		std::cout << std::endl;
	}

	void MakeHeap(std::vector<int>& buf, int _N) {
		m_size = 0;

		for (int i = 0; i < _N; i++) {
			Insert(buf[i]);
		}
	}

	void Insert(int value) {
		int pointer = m_size;

		if (isFull()) {
			std::cout << "Can not insert item to HEAP!! Current Size: " << m_size << std::endl;
		}
		else {
			// 일단 마지막 자리에 넣는다
			m_buffer[m_size] = value;
			m_size += 1;

			while (m_size > 0 && m_buffer[pointer] > m_buffer[(pointer - 1) / 2]) {
				// Max Heap에서 자식 노드는 무조건 부모노드보다 작거나 같아야 한다.
				// 끝에 삽입된 노드를 부로 노드와 비교해서 크다면 부모 노드와 교체
				Swap(pointer, (pointer - 1) / 2);
				pointer = (pointer - 1) / 2;
			}
		}
	}

	int Remove() {
		if (isEmpty()) {
			std::cout << "Can not remove item on HEAP!! Current Size: " << m_size << std::endl;
			return -1;
		}
		else {
			// Root 값을 리턴
			int res = m_buffer[0];

			// 마지막 노드값을 Root로 이동
			m_buffer[0] = m_buffer[--m_size];
			m_buffer[m_size] = 0;
			
			// Heap 재정렬
			int pointer = 0;

			while (pointer <= m_size - 1) {
				int left = 2 * pointer + 1;
				int right = 2 * pointer + 2;

				if (left >= m_size) {		// Child 존재 X
					break;
				}
				else if (right >= m_size) {	// 왼쪽 Child만 존재 
					if (m_buffer[left] > m_buffer[pointer]) {
						Swap(left, pointer);
						pointer = left;
					}
					else {
						break;
					}
				}
				else {	// 양쪽 Child 존재
					if (m_buffer[left] > m_buffer[pointer] && m_buffer[right] > m_buffer[pointer]) {
						if (m_buffer[left] < m_buffer[right]) {
							Swap(right, pointer);
							pointer = right;
						}
						else {
							Swap(left, pointer);
							pointer = left;
						}
					}
					else if (m_buffer[left] > m_buffer[pointer]) {
						Swap(left, pointer);
						pointer = left;
					}
					else if (m_buffer[right] > m_buffer[pointer]) {
						Swap(right, pointer);
						pointer = right;
					}
					else {
						break;
					}
				}
			}
			
			return res;
		}
	}

	void HeapSort() {
		int size = m_size;

		for (int i = size - 1; i >= 0; i--) {
			m_buffer[i] = Remove();
		}
	}
};