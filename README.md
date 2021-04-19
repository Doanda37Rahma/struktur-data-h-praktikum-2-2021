# struktur-data-h-praktikum-2-2021

# struktur-data-h-praktikum-1-2021

## Banyu
### Verdict
Wrong Answer

### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/bukti_banyu.png)

### Penjelasan Soal

### Penjelasan Solusi


### Visualisasi Solusi
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/gg_visual1.png)

## Roni Suka Merah
### Verdict
AC saat Praktikum 
(Karena kesalahan testcase, waktu ac saat revisi)
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/bukti_roni_suka_merah.png)

### Penjelasan Soal
Diminta memasukkan input ke dalam tree dan mengeluarkan output sesuai petunjuk: "Roni" dan "Merah"

### Penjelasan Solusi
Solusinya adalah traversal inorder dari "RoniRed". Traversal inorder adalah pengaksesan data dalam tree dari terkecil ke terbesar. Program mengakses left child kemudian mencetak kemudian mengakses right child.

### Visualisasi Solusi
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/Inorder-traversal.gif)

## Genjil Ganap V2
### Verdict
AC saat Praktikum

### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/bukti_ganjil_genap_v2.png)
### Penjelasan Soal
Diminta membuat binary search tree yang isinya angka genap semua. Jika ada input ganjil, angka genap terakhir dihapus dari tree. Diminta mengeluarkan output terkecil hingga terbesar.
### Penjelasan Solusi
Program menggunakan stack untuk menyimpan _trace_ angka genap terakhir.
Pertama program mengambil jumlah testcase.
Program mengambil input. Jika genap, masukkan angka ke tree dan stack. Jika ganjil, keluarkan angka (yang ada pada atas stack) dari tree, kemudian pop stack. Setelah selesai, keluarkan output secara inorder. 
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
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/visual_genap_ganjil_v2.png)

## MALUR TERHUBUNG
### Verdict
AC saat Praktikum

### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/bukti_malur_terhubung.png)

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
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/gg_visual1.png)

## Nadut Gabut
### Verdict
AC saat Praktikum

### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/bukti_nadut_gabut.png)

### Penjelasan Soal

### Penjelasan Solusi

### Visualisasi Solusi
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/gg_visual1.png)

## Penomoran Garasi Saha
### Verdict
AC saat Praktikum

### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/bukti_penomoran_garasi_saha.png)

### Penjelasan Soal

### Penjelasan Solusi

### Visualisasi Solusi
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/gg_visual1.png)










