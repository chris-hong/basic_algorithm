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
			// �ϴ� ������ �ڸ��� �ִ´�
			m_buffer[m_size] = value;
			m_size += 1;

			while (m_size > 0 && m_buffer[pointer] > m_buffer[(pointer - 1) / 2]) {
				// Max Heap���� �ڽ� ���� ������ �θ��庸�� �۰ų� ���ƾ� �Ѵ�.
				// ���� ���Ե� ��带 �η� ���� ���ؼ� ũ�ٸ� �θ� ���� ��ü
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
			// Root ���� ����
			int res = m_buffer[0];

			// ������ ��尪�� Root�� �̵�
			m_buffer[0] = m_buffer[--m_size];
			m_buffer[m_size] = 0;
			
			// Heap ������
			int pointer = 0;

			while (pointer <= m_size - 1) {
				int left = 2 * pointer + 1;
				int right = 2 * pointer + 2;

				if (left >= m_size) {		// Child ���� X
					break;
				}
				else if (right >= m_size) {	// ���� Child�� ���� 
					if (m_buffer[left] > m_buffer[pointer]) {
						Swap(left, pointer);
						pointer = left;
					}
					else {
						break;
					}
				}
				else {	// ���� Child ����
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