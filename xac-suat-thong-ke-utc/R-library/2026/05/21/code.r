set.seed(2024)

n <- 60

nhomA <- round(rnorm(30, mean = 72, sd = 10))
nhomA <- pmin(pmax(nhomA, 40), 100)

nhomB <- round(rnorm(30, mean = 66, sd = 12))
nhomB <- pmin(pmax(nhomB, 40), 100)

diem_truoc <- round(rnorm(n, mean = 65, sd =10))
diem_truoc <- pmin(pmax(diem_truoc, 40), 100)
cai_thien  <- round(rnorm(n, mean = 5, sd =6))
diem_sau <- pmin(pmax(diem_truoc + cai_thien, 40), 100)

tai_lieu <- sample (c(0,1), n, replace=TRUE, prob=c(0.45, 0.55))

sv <- data.frame(
    NhomHD  = c(rep('HuongDan', 30), rep('TuHoc', 30)),
    Diem = c(nhomA, nhomB),
    DiemTruoc = diem_truoc,
    DiemSau = diem_sau,
    TaiLieu = tai_lieu
)

str(sv)
summary(sv)

mu0 <- 70
alpha <- 0.75

x_bar <- mean(sv$Diem)
s_val <- sd(sv$Diem)
n_val <- nrow(sv)
cat('x_bar =', round(x_bar,3), '| s = ', round(s_val,3), '| n = ', n_val, '\n')

ket_qua1 <- t.test(sv$Diem, mu = mu0, alternative = 'two.sided')
print(ket_qua1)

ket_qua1b <- t.test(sv$Diem, mu = 70, alternative = 'less')
print(ket_qua1b)

cat('p-value hai phia: ', round(ket_qua1$p.value, 4), '\n')
cat('p-value mot phia (less): ', round(ket_qua1b$p.value, 4), '\n')
cat('Quan he: p_mot_phia = p_hai_phia / 2 (neu t < 0)\n')

ket_qua1$statistic
ket_qua1$p.value
ket_qua1$estimate

if(ket_qua1$p.value < alpha){
  cat('Bac bo H0: Co bang chung diem TB khac ', mu0, '(p = ', round(ket_qua1$p.value,4), ')\n')
}else{
    cat ('Chua du bang chung bac bo H0 (p = ', round(ket_qua1$p.value,4), ')\n')
  }

