//
// Created by coastcao(操海兵) on 2019-08-19.
//

#include "Eigen/Dense"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace Eigen;

bool read_from_file(string filename, MatrixXd& mat) {
    // read from file
    ifstream fis(filename, ios_base::in);
    const int BUF_SIZE = 1345 + 1345 * 3;
    char buf[BUF_SIZE];
    int line_index = 0;

    while (fis.getline(buf, BUF_SIZE)) {
        //cout << buf << endl;
        string buf_str = string(buf);
        stringstream s(buf_str);
        string token;
        int col_index = 0;
        while (getline(s, token, ' ')) {
            //cout << line_index << "\t" << col_index << endl;
            //cout << token << endl;
            stringstream ss(token);
            float v;
            ss >> v;
            mat(line_index, col_index) = v;
            col_index++;
        }
        line_index++;
    }

    return true;
}

int main() {

    // initialization
    Matrix2d mat;
    mat << 1, 2, 3, 4;  // or 1, 2
                        //    3, 4

    // load from file
    MatrixXd ret(2,1345);
    read_from_file("test_data/big_matrix.txt", ret);
    cout << ret << endl;

    // create special vector (similar for matrix)
    VectorXf v_tmp5 = VectorXf::Zero(2);
    cout << "get a specified zero vector:\n";
    cout << v_tmp5 << endl;

    // create a vector/matrix and then fill a value
    VectorXf v_tmp6(2);
    v_tmp6.fill(3);
    cout << "fill a vector with a constant:\n";
    cout << v_tmp6 << endl;
    MatrixXf m_tmp = MatrixXf::Zero(3,3);
    cout << "fill a row of matrix with a constant:\n";
    m_tmp.row(0).fill(2.0);
    cout << m_tmp << endl;
    cout << "fill a col of matrix with a constant:\n";
    m_tmp.col(0).fill(3.0);
    cout << m_tmp << endl;
    cout << "fill a block of matrix with a constant:\n";
    m_tmp.block<2,2>(1,1).fill(4.0);
    cout << m_tmp << endl;

    // sets a linearly spaced vector
    RowVectorXf v_tmp7 = RowVectorXf::LinSpaced(10, 1, 10);
    cout << "set a linearly spaced vector:\n";
    cout << v_tmp7 << endl;
    cout << v_tmp7.array() / 2 << endl;

    // declare and then reshape
    MatrixXf m_tmp2;
    m_tmp2.resize(2,3);
    cout << "after reshape, m_tmp2 shape:\n";
    cout << m_tmp2.rows() << ":" << m_tmp2.cols() << endl;
    cout << "m_tmp2.size():" << m_tmp2.size() << endl;

    // reshape
    MatrixXd matrix(2,6);
    matrix << 1,2,3,4,5,6,
                7,8,9,10,11,12;
    matrix.resize(2,6);
    cout << "as a (2*6) matrix:\n";
    cout << matrix << endl;
    matrix.resize(3,4);
    cout << "as a (3*4) matrix:\n";
    cout << matrix << endl;

    // block
    cout << "matrix[:,1:3]:\n";
    cout << matrix.block<3,2>(0,1) << endl;


    // matrix-matrix product
    Matrix2d product = mat * mat;
    cout << "mat * mat:" << endl;
    cout << product << endl;

    // access the elements of matrix
    for (int i = 0; i < product.rows(); i++) {
        for (int j = 0; j < product.cols(); j++) {
            cout << "product(" << i <<")(" << j << "):" << product(i,j) << endl;
        }
    }

    //cout << "use negative index:\n";
    //cout << product(-1,-1) << endl;

    // access the specified row
    RowVectorXd v_tmp2 = product.row(0);
    cout << "get the first row of product:\n";
    cout << v_tmp2 << endl;

    // matrix-vector product
    Vector2d v(1,2);
    cout << "matrxi * vector:\n";
    cout << product * v << endl;

    // matrix-vector elementwise product & addition
    RowVector2d v1(1,2), v2(3,4);
    cout << "product.array().rowwise() * v1.array():\n";
    cout << product.array().rowwise() * v1.array() << endl;
    cout << "product.array().rowwise() + v2.array():\n";
    cout << product.array().rowwise() + v2.array() << endl;

    // matrix-scalar addition
    MatrixXf m_f = MatrixXf::Random(2,3);
    cout << "raw random matrix:\n";
    cout << m_f << endl;
    cout << "四舍五入后:\n";
    MatrixXf floor_ret = (m_f.array() + 0.5f).floor();  // m_f is float, then floor() returns float
    MatrixXi int_floor_ret = floor_ret.cast<int>();     // convert float matrix to int matrix
    cout << floor_ret << endl;
    cout << int_floor_ret << endl;

    // matrix > 0 ?
    cout << "m_f.array > 0:\n";
    cout << ( m_f.array() > 0) << endl;
    // another example
    m_f << -1.3,-0.4,0,
            0.3,1.0,1.3;
    cout << "raw m_f:\n";
    cout << m_f << endl;
    MatrixXf bigger_than_one = (m_f.array() >= 1).cast<float> ();   // convert bool to float (because m_f is float type)
    m_f = 1 - bigger_than_one.array() + bigger_than_one.array() * m_f.array();
    cout << "after set the minimum, m_f:\n";
    cout << m_f << endl;

    // matrix sum
    cout << "get the total sum:\n";
    cout << m_f.sum() << endl;
    cout << "get rowwise sum:\n";
    cout << m_f.rowwise().sum() << endl;
    cout << "get the sum of first row:\n";
    cout << m_f.row(0).sum() << endl;

    // assign the specified row
    RowVector3f v_tmp1(1.0,2.0,3.0);
    m_f.row(0) = v_tmp1;
    cout << "after change the first row of m_f:\n";
    cout << m_f << endl;

    // assign the row block
    RowVector3f v_tmp3(2.0,2.0,2.0);
    m_f.block<1,3>(0,0) = v_tmp3;
    cout << "after assign the row block of m_f:\n";
    cout << m_f << endl;

    // assign the col block
    Vector2f v_tmp4(3.0,3.0);
    m_f.block<2,1>(0,0) = v_tmp4;
    cout << "after assign the col block of m_f:\n";
    cout << m_f << endl;

    // assign the block
    RowVector2f v_tmp8(4.0,5.0);
    m_f.block<2,2>(0,0).rowwise() = v_tmp8;
    cout << "after assign the block of m_f:\n";
    cout << m_f << endl;

    // another way of block (can use int, not only const, to assign index and number of row/col)
    int row_idx = 1, col_idx = 1, row_num = 1, col_num = 2;
    cout << "m_f.block(1,1,1,2):\n";
    cout << m_f.block(row_idx,col_idx, row_num, col_num) << endl;

    // transpose
    cout << "matrix block to row vector:\n";
    RowVectorXf v_tmp9 = m_f.block(0, 0, 2, 1).transpose();
    //v_tmp9.resize(1,2);
    cout << v_tmp9 << endl;

    // reverse a vector
    cout << "reverse v_tmp1:\n";
    cout << v_tmp1.reverse() << endl;

    // replicate
    cout << "v_tmp9.replicate<2,3>:\n";
    int m = 2, n = 3;
    cout << v_tmp9.replicate(m, n) << endl;

    // pow
    cout << "v_tmp9.pow(2):\n";
    cout << v_tmp9.array().pow(2) << endl;


    return 0;
}