# struktur-data-h-praktikum-2-2021

## Banyu
### Verdict
Wrong Answer

### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/bukti_banyu.png)

### Penjelasan Soal
Diberikan sebuah non-binary tree yang tiap cabang node memiliki jarak tertentu untuk melewatinya. Untuk setiap query, program diminta mencari _leaf_ terdekat dari node tertentu.

### Penjelasan & Visualisasi Solusi
Data yang digunakan berbentuk _undirected weighted graph_ yang berbentuk _tree_, dimana node adalah _vertex_ dan jarak antar node adalah _weight_. Data graph ini disimpan dalam bentuk _adjacency list_ (array), dimana setiap vertex (mulai dari 0) memiliki list yang berisi vertex tetangga dan weight (jarak).
Leaf dalam tree ini adalah vertex yang mempunyai tetangga hanya 1.
Contoh I/O:
```
7 6
0 1 5
0 3 1
1 2 8
1 4 1
3 6 1
4 5 10
3
0
4
5
```
```
6
6
5
```
Tree:
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/visual_banyu_tree.png)

Adjacency list:
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/visual_banyu_adj.png)
**Hipotesis Solusi**
Untuk setiap query `q`, program pertama mengakses list milik `q`, kemudian program menggunakan fungsi (rekursif) untuk mengunjungi setiap tetangga, sambil menghitung sum sampai ke vertex leaf, kemudian mengambil sum terkecil (dan leaf yang dikunjungi). Setelah selesai, program mengoutputkan leaf tersebut. 


## Roni Suka Merah
### Verdict
AC saat Praktikum 
(Karena kesalahan testcase, waktu ac saat revisi)
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/bukti_roni_suka_merah.png)

### Penjelasan Soal
Diminta memasukkan input ke dalam tree dan mengeluarkan output sesuai petunjuk: "Roni" dan "Merah"

### Penjelasan Solusi
Solusinya adalah traversal inorder dari "RoniRed". Traversal inorder adalah pengaksesan data dalam tree dari terkecil ke terbesar. Program mengakses left child kemudian mencetak kemudian mengakses right child.
```
int main() {
	BST tree;
	tree.init();
	
	int N;
	int num;
	
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> num;
		tree.insert(num);
	}
		
	tree.inorder();
	putchar('\n');
	
	return 0;
}

	void inorder() {
		inorderT(root);	
	}

	void inorderT(node *temp) {
		if (temp != NULL) {
			inorderT(temp->left);
		    cout << temp->key << " ";
			inorderT(temp->right);
		}
	}
```

### Visualisasi Solusi
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/Inorder-traversal.gif)

## Genjil Ganap V2
### Verdict
AC saat Praktikum

### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/bukti_ganjil_genap_v2.png)

### Penjelasan Soal
Diminta membuat binary search tree yang isinya angka genap semua. Jika ada input ganjil, angka genap terakhir dihapus dari tree. Diminta mengeluarkan output terkecil hingga terbesar.
### Penjelasan Solusi
Program menggunakan stack untuk menyimpan _trace_ angka genap terakhir.
Pertama program mengambil jumlah testcase.
Program mengambil input. Jika genap, masukkan angka ke tree dan stack. Jika ganjil, keluarkan angka (yang ada pada atas stack) dari tree, kemudian pop stack. Setelah selesai, keluarkan output secara inorder. 
```
int main() {
	BST tree;
	tree.init();
	
	Stack stack;
	stack.init();
	
	int N, num;
	
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> num;
		if (num & 1) {
			tree.remove(stack.top());
			stack.pop();
		} else {
			stack.push(num);
			tree.insert(num);
		}
	}
	
	if (tree.isEmpty()) cout << "Tree Kosong!";
	else tree.inorder();
	putchar('\n');
	
	return 0;
}
```
### Visualisasi Solusi
Contoh Input:
```
7
6
4
5
8
7
12
10
```
Output:
```
6 10 12 
```
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/visual_genap_ganjil_v2.png)

## MALUR TERHUBUNG
### Verdict
AC saat Praktikum

### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/bukti_malur_terhubung.png)

### Penjelasan Soal
Diberikan input angka dalam tree. Untuk setiap query l dan r, outputkan hasil penjumlahan subtree yang menghubungkan l dan r (l<r). Jika l/r tidak dalam tree, outputkan `-1`.
### Penjelasan Solusi
#### Fungsi Main:
```
int main() {
	BST tree;
	tree.init();
		
	int N,Q,A,L,R;
	cin >> N >> Q;
	for (int i=0; i<N; i++) {
		cin >> A;
		tree.insert(A);
	}
	for (int i=0; i<Q; i++) {
		cin >> L >> R;
		if (L>R) {
			int temp = R;
			R = L;
			L = temp;
		}
		if (tree.find(L) && tree.find(R) && !tree.isEmpty()) {
			cout << tree.sumConnectingSubtree(L, R) << endl;
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}
```
Pertama, program mengambil input `N`, banyak angka dalam tree, dan `Q`, banyak query. Kemudian program mengambil `N` angka dan memasukkan ke tree.
Kemudian untuk setiap query:
Mengambil l dan r
Menukar l dan r jika l>r
Jika l dan r ada dalam tree:
  Menjalankan fungsi sumConnectingSubtree().
  jika tidak keluarkan -1.
 
#### Fungsi sumConnectingSubtree()
```
int sumConnectingSubtree(int l, int r) {
		int sum = 0;
		scs(root, l, r, &sum);
		return sum;
	}

void scs(node* t, int l, int r, int* sum) {
		if (t!=NULL) {
			if (t->key>r) 
				scs(t->left, l, r, sum);
			else if (t->key<l) 
				scs(t->right, l, r, sum);
			else {
				scs_recur(t, sum);
			}
		}
	}
  
void scs_recur(node *t, int* sum) {
		if (t != NULL) {
			*sum += t->key;
			scs_recur(t->left, sum);
			scs_recur(t->right, sum);
		}
	}
```
Fungsi ini mencari subtree yang menghubungkan l dan r (subtree pertama yang bernilai inklusif antara l dan r, subtree ini pasti root teratas yang dilalui saat menghubungkan l dan r, karena ) dengan fungsi `scs`. Mulai dari root, jika value > r, ke kiri, jika value < l, ke kanan. Setelah ketemu subtree yang dicari, maka menghitung jumlah setiap anggota dalam subtree dengan fungsi `scs_recur` yang menggunakan traversing preorder.

### Visualisasi Solusi
INPUT:
```
8 1
8 3 10 1 6 14 4 7 
3 7 
```
OUTPUT:
```
21
```

![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/visual_malur.png)

## Nadut Gabut
### Verdict
AC saat Praktikum

### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/bukti_nadut_gabut.png)

### Penjelasan Soal
Diberikan suatu tree, program diminta menentukan apakah ada penjumlahan tiga node terhubung yang menghasilkan jumlah tertentu `sum` dalam tree.
### Penjelasan Solusi
Main program:
```
int main() {
	BST tree;
	tree.init();
	
	int t, sum, n;
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		tree.insert(n);
	}
	cin >> sum;
	
	bool result = tree.findJumlahTiga(sum);
	
	if (result) cout << "Penjumlahan angka di tree yang menghasilkan " << sum << " ditemukan" << endl;
	else cout << "Tidak ditemukan penjumlahan angka di tree yang menghasilkan " << sum << endl;

	return 0;
}
```
Program menggunakan fungsi bool `findJumlahTiga()`. Fungsi ini menjumlahkan tiap kombinasi 3 node terhubung dan mengecek apakah jumlahnya sebesar `sum`.
```
	bool findJumlahTiga(int value) {
		bool result = findtiga(root, value);
		return result;
	}
```
Terdapat 5 kemungkinan hubungan 3 node dalam tree.
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/visual_ng.png)

Tiap kemungkinan ini dicek dalam fungsi rekursif `findtiga()`:
```
	bool findtiga(node *temp, int value) {
		if (temp != NULL) {
			int sum;
			if (temp->left) {
				if (temp->right) {
					sum = temp->key + temp->left->key + temp->right->key;
					if (sum == value) return true;
				}
				if (temp->left->left) {
					sum = temp->key + temp->left->key + temp->left->left->key;
					if (sum == value) return true;
				}
				if (temp->left->right) {
					sum = temp->key + temp->left->key + temp->left->right->key;
					if (sum == value) return true;
				}
			}
			if (temp->right) {
				if (temp->right->right) {
					sum = temp->key + temp->right->key + temp->right->right->key;
					if (sum == value) return true;
				}
				if (temp->right->left) {
					sum = temp->key + temp->right->key + temp->right->left->key;
					if (sum == value) return true;
				}
			}
			if (findtiga(temp->left, value) ||
				findtiga(temp->right, value))
				return true;
			else
				return false;			 
		}
		return false;
	}
```
### Visualisasi Solusi
INPUT:
```
10
73 66 91 53 72 77 98 74 78 79
266
```
OUTPUT:
```
Penjumlahan angka di tree yang menghasilkan 266 ditemukan
```
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/visual_ng2.png)

## Penomoran Garasi Saha
### Verdict
AC saat Praktikum

### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/bukti_penomoran_garasi_saha.png)

### Penjelasan Soal
Diberikan sebuah tree. Program diminta mendata node tree pada tingkat terbawah sampai tingkat teratas dengan pola nilai minimal, maksimal, minimal, dst.

### Penjelasan Solusi
Berikut fungsi main:
```
int main() {
	BST tree;
	tree.init();
		
	int P, num, h;
	
	cin >> P;
	for (int i=0; i<P; i++) {
		cin >> num;
		tree.insert(num);
	}

	h = tree.height();	
	int A[h+1];
	for (int j=1; j<h; j+=2) 
		A[j] = 0;

	if (h & 1) {
		tree.penomoranGarasi(&A[0], 1);
	} else {
		tree.penomoranGarasi(&A[0], 0);
	}
	
	for (int k=h-1; k>=0; k--) {
		cout << A[k] << " ";
	}
	
	return 0;
}
```
Program diminta untuk menentukan output dengan pola min-max-min dari tingkat terbawah sampai ke atas, maka dari root ke tingkat bawah ada dua kemungkinan:
Jika jumlah tingkat dalam tree `h` ganjil, maka dari tingkat atas ke bawah min-max-min. Jika genap maka max-min-max. Jumlah tingkat tree ditentukan melalui fungsi `height()` yang memanggil fungsi rekursi `maxh()`.
```
	int height() {
		return maxh(root);
	}

	int maxh(node* temp) {
		if (temp==NULL) return 0;
		else 
		{
			int lefth = maxh(temp->left);
			int righth = maxh(temp->right);
			
			if (lefth > righth) 
				return lefth+1;
			else return righth+1;
		}
	}
```
Berdasarkan jumlah tingkat `h`, program akan menentukan max/min setiap tingkat tree (sesuai pola) dan memasukkannya ke array `A` melalui fungsi `penomoranGarasi()`. 

#### Fungsi penomoranGarasi()
```
	void penomoranGarasi(int *arr, int genapmin) {
		int h=0;
		if (genapmin) 
			garasiA(root, h, arr);
		else garasiB(root, h, arr);
	}
```
Fungsi ini memanggil salah satu dari 2 fungsi utility. `genapmin` disini mengindikasikan pola min-max-min jika `true`, sehingga memanggil fungsi rekursif `garasiA()`.
```
	void garasiA(node* t, int h, int* arr) {
		if (t != NULL) {
			if (arr[h] == 0) {
				arr[h] = t->key;
			} else {
				if (h & 1) {
					if (t->key > arr[h])
						arr[h] = t->key;
				} else {
					if (t->key < arr[h])
						arr[h] = t->key;
				}
			}
			garasiA(t->left, h+1, arr);
			garasiA(t->right, h+1, arr);
		}
	}
```
Disini dicek dan diupdate nilai min/max setiap tingkat (`h`, tingkat teratas = 0). jika `h` genap, dicari nilai min, dan jika ganjil sebaliknya, sehingga pola pada array min-max-min. Untuk fungsi `garasiB()` sama persis, hanya jika `h` genap, dicari nilai max dan sebaliknya.
```
	void garasiB(node* t, int h, int* arr) {
		if (t != NULL) {
			if (arr[h] == 0) {
				arr[h] = t->key;
			} else {
				if (h & 1) {
					if (t->key < arr[h])
						arr[h] = t->key;
				} else {
					if (t->key > arr[h])
						arr[h] = t->key;
				}
			}
				garasiB(t->left, h+1, arr);
			garasiB(t->right, h+1, arr);
		}
	}
```
Setelah mendapat data sesuai pola dalam array, karena output harus dari tingkat bawah ke atas, program meng-output-kan array dari belakang.

### Visualisasi Solusi
INTRO
```
7
500
250
750
125
375
625
875
```
OUTPUT
```
125 750 500
```
Disini jumlah tingkat tree adalah 3(ganjil), maka pola dari atas adalah min-max-min

![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-2-2021/blob/main/img/visual_pgs.png)










