# Thong ke mau
so_lam_them <- sum(sv$LamThem)
n_p <- nrow (sv)
p_hat <- so_lam_them / n_p
cat('So sinh vien lam them:', so_lam_them, '/', n_p, '\n')
cat('Ti le mau p_hat =', round (p_hat, 4), '\n')
# Kiem tra dieu kien ap dung phan phoi Z
dk1 <- n_p * p_hat
dk2 <- n_p * (1 - p_hat)
cat ('n*p_hat = ', dk1, '(can >= 5)\n')
cat('n*(1-p_hat) =', dk2, '(can >= 5)\n')
cat('Du dieu kien:', dk1 >= 5 & dk2 >= 5 , '\n')
# Cach 1: Tinh tay
z_p <- qnorm(0.975) # alpha = 0.05
se_p <- sqrt(p_hat * (1-p_hat) / n_p)
E_p <- z_p * se_p
cat('\n=== Khoang tin cay 95% cho ti le lam them ===\n')
cat('p_hat', round(p_hat, 4), '\n')
cat ('SE (p) =', round(se_p, 4), '\n')
cat ('Bien do E', round (E_p, 4),'\n')
cat('KTC: [', round(p_hat-E_p, 4), ';', round (p_hat+E_p, 4), ']\n')
# prop.test() tinh KTC cho ti le
ket_qua_p <- prop.test(x = so_lam_them, # so 'thanh cong'
                       n = np,          # co mau
                       conf.level = 0.95,
                       correct = FALSE) # khong hieu chinh Yates
print (ket_qua_p)
# Trich xuat KTC
ktc_p <- ket_qua_p$conf.int
cat('\nKTC 95%: [', round (ktc_p[1],4), ';', round (ktc_p [2],4), ']\n')
# Ham tinh KTC cho ti le (viet mot lan, dung nhieu lan)
ktc_tile <- function(x, n, conf = 0.95, ten = 'Ti le') {
   p_h <-x/n
   Z_V <- qnorm (1 + (- (1 - conf)) / 2)
   # qnorm(): tim gia tri toi han cua phan phoi chuan (Z)
   # conf: ten bien tu dat [for (conf in muc_tin_cay)]
   se_v <- sqrt(p_h* (1 - p_h) / n)
   E_v <- Z_V * se_v
cat (ten, ':\n')
cat('p_hat =', round (p_h,4), '| n =', n, '\n')
cat(' KTC', conf*100, '%: [', round(p_h-E_v,4), ';', round (p_h+E_v,4), ']\n\n')
}
ktc_tile (sum(sv$LamThem), nrow(sv), ten = 'Sinh vien lam them')
ktc_tile (sum(sv$DungThuVien), nrow(sv), ten = 'Sinh vien dung thu vien')