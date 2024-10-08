# what is OCF
## C++のクラスにおいて、リソース管理を適切に行うために推奨される特別メンバ関数（デストラクタ、コピーコンストラクタ、コピー代入演算子、ムーブコンストラクタ、ムーブ代入演算子）の実装ガイドラインを指します

1. デストラクタ :objectが破棄される際に、割り当てられたリソースを解放します
```
~ClassName() {
    // クリーンアップコード
}
```
2. コピーコンストラクタ :他のオブジェクトのコピーとして新しいオブジェクトを作成します
```
ClassName(const ClassName& other) {
    // コピーコード
}
```
3. コピー代入演算子 :既存のオブジェクトに他のオブジェクトの状態を代入します
```
ClassName& operator=(const ClassName& other) {
    if (this != &other) {
        // クリーンアップコード
        // コピーコード
    }
    return *this;
}
````

4. デフォルトコンストラクタ	:デフォルトコンストラクタは、クラスのオブジェクトが生成される際に適切な初期状態にするために使用されます 

5. ムーブコンストラクター :c++11以降らしい

6. ムーブ代入演算子 :同上

## RAII
コンストラクタで必要なメモリを確保してデストラクターで解放すること

## コンストラクタの種類
コンストラクタにはプログラマが書いたユーザ定義コンストラクタの他にコンパイラが自動で生成するユーザ定義コンストラクタがある
コンパイラ生成コンストラクタの中にはクラスをコピーする際に使われるコピーコンストラクタがある


## コピーコンストラクタ
 多くの場合、コンパイラが作成するコピーコンストラクタで問題ないが、コピー対象のクラスがメモリやリソース領域を扱う場合
ポインタ変数の値のみをコピーし、ポインターの指す実際のオブジェクトはコピーしない
オブジェクトが１つしか存在しないのに複数のクラスで同じアドレスを持ってしまいdouble freeとなる

## constメンバー関数
クラスはメンバー変数や関数を用いてさまざまな機能をクラスの外部に提供できます
しかし、メンバー関数がメンバー変数を変更するかどうかはいっけん見ただけではわからない
コンパイラは基本的にメンバー関数をメンバー変数を変更するものとして扱う
そのためconstなインスタンスに対するメンバー関数の呼び出しをエラーとして処理する
しかし、getterなどの本来メンバー変数を変更しない関数は呼び出したいのでconstメンバー関数をつかってよびだせる

```
class a
{
public:
	return-type menber-function(param...) const;
}

return-type class-name::member-function-name(param...) const
{
	function-body...
}
```

関数のオーバーロードで引数の違いと同様に関数がconstかどうかでメンバー関数のオーバーロードを定義できる
どちらの関数が呼ばれるかはインスタンスがconstかどうかによる

## 演算子オーバーロード

## thisポインタ
メンバー関数はクラス内の他のメンバーを直接参照できますが、仮引数の名前もメンバー関数と同じ場合
メンバー関数の中ではメンバーではなく仮引数を表すことになっている
メンバー関数の中で仮引数やメンバーの名前に依存せずメンバーにアクセスするにはthisポインタを利用できます
thisポインターにはそのメンバー関数呼び出しに使われたオブジェクトを指し示すポインターが格納されています
thisポインター自体の値は変更できません
thisポインターはコンパイラが自動で使えるように用意されているポインターなので宣言できません

```
class class-name
{
	int value;
public:
	return-type class-name::member-function-name(int value)
	{
		value = value;//引数のこと	
		this->value = value;
	}
}
```
## staticクラスメンバー
staticクラスメンバーは特定のインスタンスと結びつかないメンバー変数や関数
### staticメンバー変数

### staticメンバー関数

## 固定小数点
固定小数点（Fixed Point）数値表現は、コンピュータで小数を扱う方法の一つであり、整数部と小数部のビット数が固定された形式です。これは、浮動小数点数（Floating Point）と対照的で、固定された小数点位置に基づいて数値を表現します。

### 固定小数点数の特徴
1. 固定された小数点位置:
小数点の位置が予め定義されており、数値はこの位置に基づいて解釈されます。
例えば、8ビットの小数部を持つ固定小数点数では、数値は整数部と小数部に分割され、8ビットの小数部が使用されます。

2. 固定精度:
固定小数点数の精度はビット数によって決まります。整数部と小数部のビット数を変更することで精度を調整できます。
例えば、16ビットの固定小数点数で8ビットが小数部に割り当てられている場合、小数部は2^-8の精度で表現されます。

3. パフォーマンス:
固定小数点数は、浮動小数点数よりも計算が高速で、特にハードウェアで直接サポートされていないシステムでは有利です。
特に、組み込みシステムやリアルタイムシステムでよく使用されます。

### 固定小数点数の例
例えば、8ビットの小数部を持つ16ビットの固定小数点数を考えます。

数値 3.25 を固定小数点数で表現するには、3と0.25の部分に分けます。
3 は整数部で、2^0 * 3 = 3 なのでそのまま3。
0.25 は小数部で、2^-2 = 0.25 なので、2^-2のビットが1になります。
数値 3.25 は以下のように表現されます：

```
整数部 (8ビット): 00000011 (3)
小数部 (8ビット): 01000000 (0.25)
固定小数点表現: 0000001101000000
```
