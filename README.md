# DSA
Có **n** thành phố. Một số trong số chúng được kết nối, trong khi một số thì không. Nếu thành phố **a** được kết nối trực tiếp với thành phố **b** và thành phố **b** được kết nối trực tiếp với thành phố **c**, thì thành phố **a** được kết nối gián tiếp với thành phố **c**.

Tỉnh là một nhóm các thành phố được kết nối trực tiếp hoặc gián tiếp và không có thành phố nào khác ngoài nhóm.

Bạn được cung cấp một ma trận **n x n** isConnected trong đó **isConnected[i][j] = 1** nếu thành phố thứ **i** và thành phố thứ **j** được kết nối trực tiếp và **isConnected[i][j] = 0** nếu không.

Tính số lượng các tỉnh.

- Ví dụ:
![image](https://user-images.githubusercontent.com/92845822/174081873-13ada441-a992-4ee6-9de3-8742c34104b5.png)

> Bài gốc: [Leetcode - Number of Provinces](https://leetcode.com/problems/number-of-provinces/) 