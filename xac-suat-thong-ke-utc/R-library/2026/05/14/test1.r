set.seed (2024)
n <- 50
gpa <- round (rnorm(n, mean = 2.85, sd = 0.45 ), 2)
gpa <- pmin (pmax (gpa, 1.0), 4.0) #gioi han trong [1.0, 4.0]
gio_tu_hoc <- round (rnorm(n, mean = 3.2, sd = 1.1 ),1)
# n: So luong so ngau nhien muon tao
# mean = 3.2: Trung binh (mean) cua phan phoi la 3.2.
# sd = 1.1: do lech chuan (standard deviation) cua phan phoi la 1.1.
gio_tu_hoc <- pmax (gio_tu_hoc, 0)
co_lam_them <- sample (c(0, 1), n, replace = TRUE, prob = c(0.6, 0.4))
dung_thu_vien <- sample (c(0, 1), n, replace = TRUE, prob = c(0.45, 0.55))
# probability: xac suat
sv <- data.frame(
  GPA = gpa,
  GioTuHoc = gio_tu_hoc, # 1 = co lam them
  LamThem = co_lam_them, # 1 thuong xuyen dung thu vien
  DungThuVien = dung_thu_vien
)
# Kiem tra nhanh
str(sv)
summary (sv)
# Cac chi so can dung trong uoc luong
x_bar <- mean (sv$GPA) # Trung binh mau
s <- sd(sv$GPA) # Do lech chuan mau
n <- nrow (sv) # Co mau
se <- s / sqrt(n) # Sai so chuan (standard error)
cat('n =', n, '\n')
cat ('n =', round(x_bar, 4), '\n')
cat('s =', round (s, 4), '\n')
cat('se =', round(se, 4), '\n')
# Ty le sinh vien co lam them
p_hat <- mean (sv$LamThem) # = so nguoi lam them / n
cat('p_hat (lam them) =' , p_hat, '\n')