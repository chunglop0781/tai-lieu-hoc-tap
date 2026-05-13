# --- PHẦN 0: CHUẨN BỊ DỮ LIỆU ---
data(iris)
# ?iris # Xem mô tả chi tiết (chạy trong console)

# --- PHẦN 1: KHÁM PHÁ ---
# Kiểm tra cấu trúc dữ liệu tương tự cách làm ở Source [1]
dim(iris)        # Số hàng x số cột [1]
names(iris)      # Tên các biến [1]
str(iris)        # Cấu trúc: xác nhận 150 quan sát, 5 biến, Species là factor 3 mức [1]
class(iris)      # Xác nhận kiểu đối tượng là Data Frame [1]

# --- PHẦN 2: THỐNG KÊ ---
# Tính toán các chỉ số xu hướng trung tâm và phân tán [2]
# Đối với Sepal.Length
mean_sl <- mean(iris$Sepal.Length)
med_sl  <- median(iris$Sepal.Length)
sd_sl   <- sd(iris$Sepal.Length)

# Đối với Petal.Length
mean_pl <- mean(iris$Petal.Length)
med_pl  <- median(iris$Petal.Length)
sd_pl   <- sd(iris$Petal.Length)

# Xuất kết quả làm tròn theo tư duy ở Source [3], [4]
cat('Sepal.Length - Mean:', round(mean_sl, 2), 'Median:', med_sl, 'SD:', round(sd_sl, 2), '\n')
cat('Petal.Length - Mean:', round(mean_pl, 2), 'Median:', med_pl, 'SD:', round(sd_pl, 2), '\n')

# --- PHẦN 3: NHÓM ---
# So sánh Petal.Length trung bình theo từng loài bằng tapply [5]
tapply(iris$Petal.Length, iris$Species, mean)

# Hoặc dùng aggregate để linh hoạt hơn như Source [5]
aggregate(Petal.Length ~ Species, data = iris, FUN = mean)

# --- PHẦN 4: HISTOGRAM ---
# Vẽ biểu đồ tần suất kèm đường cong mật độ như Source [6]
hist(iris$Petal.Length, freq = FALSE, 
     col = 'lightblue', border = 'white',
     main = 'Phân phối Petal.Length', 
     xlab = 'Chiều dài cánh hoa (cm)', ylab = 'Mật độ')
lines(density(iris$Petal.Length), col = 'red', lwd = 2) # Thêm đường cong mật độ màu đỏ [6]

# --- PHẦN 5: BOXPLOT ---
# Vẽ boxplot so sánh Sepal.Length theo Species
# Sử dụng bảng màu và cách đặt tên như Source [7], [8]
boxplot(Sepal.Length ~ Species, data = iris,
        main = 'So sánh Sepal.Length theo Loài',
        xlab = 'Loài (Species)', ylab = 'Chiều dài đài hoa (cm)',
        col = c('#3498db', '#e74c3c', '#2ecc71'))

# --- PHẦN 6: SCATTER ---
# Vẽ biểu đồ phân tán giữa Petal.Length và Petal.Width phân màu theo loài [8]
plot(iris$Petal.Length, iris$Petal.Width,
     main = 'Mối quan hệ Petal.Length và Petal.Width',
     xlab = 'Petal.Length (cm)', ylab = 'Petal.Width (cm)',
     pch = 19, 
     col = iris$Species, # Phân màu theo factor Species
     cex = 1.2)
# Thêm chú giải như Source [8]
legend('topleft', legend = levels(iris$Species), 
       col = 1:3, pch = 19, bty = 'n')

# --- PHẦN 7 (*): MỞ RỘNG ---
# Tính đồng thời mean và sd của cả 4 biến đo lường theo từng loài [5]
aggregate(. ~ Species, data = iris, 
          FUN = function(x) c(Mean = round(mean(x), 2), SD = round(sd(x), 2)))
