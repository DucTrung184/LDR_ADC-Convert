# Dự án ESP32 Đọc Cảm Biến Ánh Sáng (LDR) và Hiển Thị Dữ Liệu Bằng Teleplot

## 1. Giới thiệu

Dự án này sử dụng vi điều khiển **ESP32** để đọc tín hiệu analog từ **cảm biến quang (LDR)** và hiển thị giá trị cường độ ánh sáng theo thời gian trên **Teleplot** – một công cụ trực quan hóa dữ liệu thời gian thực qua Serial.  

Mục tiêu là giúp người học nắm được cách:

- Đọc giá trị ADC từ chân analog của ESP32.  
- Gửi dữ liệu theo định dạng Teleplot để vẽ đồ thị trực tiếp.  
- Quan sát sự thay đổi ánh sáng qua tín hiệu LDR.

---

## 2. Phần cứng sử dụng

| Thành phần | Chức năng | Ghi chú |
|-------------|------------|---------|
| ESP32 DevKit v1 | Vi điều khiển chính | Kết nối máy tính qua USB |
| LDR (Light Dependent Resistor) | Cảm biến ánh sáng | Dùng điện trở quang thay đổi theo ánh sáng |
| Điện trở 10kΩ | Điện trở kéo xuống | Tạo mạch chia áp với LDR |
| Dây nối (jumper) | Kết nối | Male-Female |

### Sơ đồ kết nối

LDR ---+--- 3.3V

|
+--- GPIO39 (VN)

|
10kΩ

|
GND

> **Gợi ý:** GPIO39 tương ứng chân `VN` trên board ESP32, là một chân ADC nội vào tốt.

---

## 3. Mô tả chương trình

Chương trình được viết bằng **C++ trên PlatformIO**.  
Nhiệm vụ chính:

1. Đọc giá trị điện áp từ mạch chia áp (LDR + điện trở).  
2. In giá trị ADC ra Serial theo định dạng Teleplot:
   Light: <giá trị>
3. Teleplot sẽ tự động nhận dữ liệu qua Serial và hiển thị đồ thị thời gian thực.

**Tốc độ baud:** `115200`

---

## 4. Kết quả hiển thị

Sau khi chạy chương trình và mở Teleplot, giá trị ánh sáng sẽ được hiển thị thành đồ thị biến thiên theo thời gian.
<img width="831" height="389" alt="ADC LDR" src="https://github.com/user-attachments/assets/39ff05e4-d469-46ec-b123-fb695c46d7e9" />

---

## 5. Cách chạy dự án

### Yêu cầu

1. PlatformIO (cài trên VSCode).
2. ESP32 board driver.
3. Teleplot extension (VSCode → Marketplace → “Teleplot”).

### Các bước thực hiện

1. Mở project bằng PlatformIO.
2. Cắm ESP32 vào máy tính (chọn đúng cổng COM).
3. Nhấn Upload để nạp chương trình.
4. Mở cửa sổ Teleplot (tab bên trên hoặc thanh công cụ dưới cùng).
5. Chọn Serial port phù hợp (tốc độ 115200).
6. Quan sát đồ thị hiển thị cường độ ánh sáng thay đổi khi che hoặc chiếu đèn vào LDR.

---

## 6. Kết luận

Kết quả cho thấy cường độ ánh sáng được biểu diễn trực quan, giúp người học hiểu rõ hơn về:
1. Hoạt động của cảm biến LDR và ADC trên ESP32.
2. Cách truyền dữ liệu real-time từ vi điều khiển sang Teleplot.
3. Ứng dụng của PlatformIO và Teleplot trong lập trình nhúng hiện đại.

---

## 7. Thông tin tác giả

Họ tên: Mai Đình Đức Trung
