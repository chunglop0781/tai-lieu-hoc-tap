# --- CHUẨN BỊ DỮ LIỆU ---
data(mtcars)
# ?mtcars # Xem mô tả chi tiết các biến như mpg, cyl, hp, wt

# --- PHẦN 1: KHÁM PHÁ (Tư duy từ Source 1, 2, 3) ---
# Kiểm tra cấu trúc cơ bản
dim(mtcars)        # 32 quan sát và 11 biến [1]
names(mtcars)      # Tên các biến kỹ thuật [1]
str(mtcars)        # Kiểu dữ liệu từng biến [1]
summary(mtcars)    # Tóm tắt sơ bộ giá trị các biến [2]

# --- PHẦN 2: THỐNG KÊ (Tư duy từ Source 2, 4) ---
# Tính toán cho mpg (Miles/(US) gallon)
mean_mpg <- mean(mtcars$mpg)
med_mpg  <- median(mtcars$mpg)
sd_mpg   <- sd(mtcars$mpg)

# Tính toán cho hp (Gross horsepower)
mean_hp <- mean(mtcars$hp)
med_hp  <- median(mtcars$hp)
sd_hp   <- sd(mtcars$hp)

# Xuất kết quả làm tròn như Source 2 [3, 4]
cat('MPG - Trung bình:', round(mean_mpg, 2), '| Trung vị:', med_mpg, '| SD:', round(sd_mpg, 2), '\n')
cat('HP  - Trung bình:', round(mean_hp, 2), '| Trung vị:', med_hp, '| SD:', round(sd_hp, 2), '\n')

# --- PHẦN 3: NHÓM (Tư duy từ Source 4) ---
# So sánh mpg trung bình theo số xi-lanh (cyl)
tapply(mtcars$mpg, mtcars$cyl, mean) # [2]
# Hoặc dùng aggregate để xem bảng rõ hơn
aggregate(mpg ~ cyl, data = mtcars, FUN = mean)

# --- PHẦN 4: HISTOGRAM (Tư duy từ Source 4) ---
# Vẽ histogram mpg với đường cong mật độ [5]
hist(mtcars$mpg, freq = FALSE, 
     col = 'lightblue', border = 'white',
     main = 'Phân phối của MPG (Tiêu hao nhiên liệu)',
     xlab = 'Miles per Gallon', ylab = 'Mật độ')
lines(density(mtcars$mpg), col = 'red', lwd = 2) 

# --- PHẦN 5: BOXPLOT (Tư duy từ Source 4) ---
# So sánh mpg theo nhóm cyl (chuyển cyl thành factor để vẽ đẹp hơn)
boxplot(mpg ~ factor(cyl), data = mtcars,
        main = 'So sánh MPG theo số Xi-lanh',
        xlab = 'Số lượng Xi-lanh (cyl)', ylab = 'Dặm trên mỗi Gallon (mpg)',
        col = c('#3498db', '#e74c3c', '#2ecc71')) # Màu sắc từ Source 4 [6]

# --- PHẦN 6: SCATTER PLOT (Tư duy từ Source 4) ---
# Mối quan hệ giữa khối lượng (wt) và tiêu hao nhiên liệu (mpg)
plot(mtcars$wt, mtcars$mpg,
     main = 'Mối quan hệ giữa Khối lượng và MPG',
     xlab = 'Khối lượng xe (1000 lbs)', ylab = 'MPG',
     pch = 19, col = factor(mtcars$cyl), cex = 1.3) # Phân màu theo cyl [7]
legend('topright', legend = levels(factor(mtcars$cyl)), 
       col = 1:3, pch = 19, title = 'Số xi-lanh', bty = 'n')

# --- PHẦN 7 (*): MỞ RỘNG (Tư duy từ Source 4) ---
# Bảng tổng hợp đồng thời mean, median, sd cho cả mpg và hp theo cyl
aggregate(cbind(mpg, hp) ~ cyl, data = mtcars, 
          FUN = function(x) c(Mean = round(mean(x), 2), 
                             Median = median(x), 
                             SD = round(sd(x), 2))) # [2]
