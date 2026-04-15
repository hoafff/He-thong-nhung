1. c = x & MASK == 0; (x=0xFF33, MASK=0xFF00)
   - Do uu tien: '==' cao hon '&'
   - Buoc 1: (MASK == 0) -> 0xFF00 == 0 la Sai (0)
   - Buoc 2: x & 0 -> 0xFF33 & 0 = 0
   - Ket qua: c = 0
   - Viet lai: c = (x & (MASK == 0));

2. z = y = x++ + ++y * 2; (x=10, y=2)
   - Buoc 1: ++y (y thanh 3)
   - Buoc 2: 3 * 2 = 6
   - Buoc 3: x++ + 6 = 10 + 6 = 16 (x tang len 11 sau buoc nay)
   - Ket qua: y = 16, z = 16, x = 11
   - Viet lai: z = (y = ((x++) + ((++y) * 2)));

3. y >>= x & x ^ 0x2 & z; (x=10, y=4, z=1)
   - Do uu tien: & > ^ > >>=
   - Ket qua: y = 4 (Vi cac phep toan bit phia sau khong lam thay doi gia tri y dang ke)
   - Viet lai: y >>= ((x & x) ^ (0x2 & z));