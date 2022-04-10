# فروشگاه موبایل با زبان c++



در این پروژه هدف بر این است که برنامه‌ای ساده و کاربردی برای فروشگاه موبایل بنویسید.
موبایل‌ها از ساختار و ویژگی‌های زیر برخوردار هستند: 

- name
- brand
- OS: enum {iOS, Android, windows phone}
- Ram: enum {2GB, 4GB, 6GB, 8GB, 12GB, 16GB, 32GB, 64GB}
- Storage: enum {16GB, 32GB, 64GB, 128GB, 256GB, 512GB, 1TB, 2TB}
- price
- Color: enum
- stock // موجودی
- sell // تعداد فروش


برای ذخیره سازی لیستی از موبایل‌ها باید از آرایه پویا استفاده شود که سایز آن بعد از اضافه کردن هر موبایل زیاد گردد.
سایز آرایه در ابتدا صفر می‌باشد.

## توابع

### add_phone
برای افزودن موبایل پیاده سازی شده و ورودی آن از جنس Mobile می باشد.
با گرفتن نام و برند موبایل یک موبایل به آرایه پویا اضافه کند.
موبایل ها می‌باست بر مبنای نام و برند یکتا باشند و موبایل تکراری در آرایه ذخیره نشود.

### remove_phone
با گرفتن ورودی index آن موبایل را حذف کند و سپس تمام خانه‌های بعد از آن را به چپ شیفت داده و آرایه را shrink کند.
### search
با گرفتن نام و برند index موبایل در آرایه برگردانده شود و در صورت نیافتن موبایلی با این مشخصات -1  را برگرداند.
### sort_by_price
آرایه اصلی موبایل ها را بر اساس قیمت مرتب می کند.
### change_mobileinfo
با گرفتن نام و برند ویژگی های موبایل را تغییر می‌دهد.
### sell_a_phone
با گرفتن نام و برند موبایل مقدار sell  را برای آن ۱ عدد افزایش داده و از موجودی آن کم می کند و در نهایت اطلاعات جدید موبایل را نمایش می دهد.
### print_phones
اطلاعات همه موبایل ها را چاپ می کند.
### most_sold_item
موبایل ها را به ترتیب پرفروش‌ترین ها چاپ می کند. (تغییری در آرایه اصلی نمی دهد.)

## منو


[1] Add a phone

[2] Remove a phone

[3] Sort phones by price

[4] Search a phone

[5] Change mobile info

[6] Sell a phone

[7] Print phones

[8] Print phones sorted by the most sold to the least

[9] Quit

[1] :: با انتخاب گزینه اول، نام و شرکت تولیدی را به عنوان ورودی دریافت کند، در صورت عدم وجود موبایل با مشخصات وارد شده،
مابقی اطلاعات موبایل را از فروشنده بگیرد و آن را به آرایه اضافه کند. اگر موبایل با این نام و شرکت تولیدی وجود داشت، یک 
عدد صحیح دریافت کند و آن را به تعداد موجودی موبایل اضافه کند.

[2] :: با انتخاب گزینه دوم، نام و شرکت تولیدی را دریافت کند و آن موبایل را از آرایه حذف کند. در صورت عدم وجود موبایل پیغام 
مناسبی چاپ شود.

[3] :: با انتخاب گزینه سوم، آرایه را بر اساس قیمت موبایل مرتب کند. (این عملیات بر روی آرایه اصلی تاثیر می گذارد.)

[4] :: با انتخاب گزینه چهارم، نام و شرکت تولیدی موبایل را دریافت کرده و اطلاعات آن را نمایش دهد. اگر موبایل با مشخصات وارد 
شده در لیست موجود نبود، پیغام مناسبی چاپ شود.

[5] :: با انتخاب گزینه پنجم، نام و شرکت تولیدی موبایل دریافت شود تا فروشنده بتواند بعضی اطلاعات موبایل را تغییر دهد. این 
تغییرات باید در لیست اصلی موبایل‌های موجود اعمال شود( می توانید برای تغییرات مشخصات موبایل، menu ای بنویسید تا 
فروشنده آیتم مورد نظرش را تغییر دهد.)

[6] :: با انتخاب گزینه ششم، با گرفتن نام و شرکت تولیدی موبایل، از تعداد موجودی آن کم کند و به تعداد فروخته شده‌ها اضافه کند.
در صورت موجود نبودن آن موبایل، پیغام مناسبی چاپ شود.

[7] :: با انتخاب گزینه هفتم، تمامی اطلاعات موبایل ها در لیست چاپ شود.

[8] :: با انتخاب گزینه هشتم، تمامی اطلاعات موبایل ها به ترتیب پرفروش‌ترین چاپ شود. (این گزینه آرایه اصلی را مرتب نمی‌کند)

[9] :: با انتخاب گزینه نهم، اطلاعات موبایل ها در فایل ذخیره و برنامه بسته میشود.

## محدودیت ها

- می بایست OS ،Ram ،Storage و Color به صورت enum تعریف شوند.
- برای sort کردن نمیتوانید از تابع آماده استفاده کنید.
- برای ذخیره سازی موبایل‌ها فقط می‌توانید از آرایه پویا استفاده کنید. استفاده کردن از vector ,set و ... غیر مجاز است.
- با هر بار اضافه و حذف کردن موبایل، حافظه ای که آرایه اشغال میکند باید اضافه و کم شود. 
- توابع بالا را ابتدا تعریف کنید و از آنها در منو استفاده کنید.

## اختیاری

تابع save_into_file را پیاده سازی کنید که اطلاعات موبایل‌های موجود در لیست را در یک فایل ذخیره کند.

تابع load_from_a_file را پیاده سازی کنید که اطلاعات موبایل‌های موجود در لیست را از فایل بخواند و در آرایه
پویا ذخیره سازی کند.

(توجه داشته باشید که هربار برنامه اجرا میشود باید اطلاعات از فایل خوانده شده و هنگام بستن، اطلاعات در فایل ذخیره 
شوند.)

این قابلیت را به برنامه اضافه کنید که فروشنده با استفاده از آرگومانهای خط فرمان بتواند موبایل به فایل اضافه کند یا یک موبایل
را حذف کند منو نمایش داده نمیشود. برای مثال:

`` $phonestore.exe add <phone_name> <manufacturer> <count> ``

`` $phonestore.exe remove <phone_name> <manufacturer> <count> ``

دستور اول موبایل، نام و شرکت شرکت تولیدی و تعداد موجودی را به عنوان آرگومان میگیرد. در صورتی که موبایل از قبل در 
فایل موجود باشد، count را به تعداد موجودی اضافه میکند در غیر این صورت موبایل را به فایل اضافه میکند (مابقی مشخصات 
را به صورت پیش فرض درنظر بگیرید.)
دستور دوم با گرفتن نام و شرکت شرکت تولیدی موبایل، تعداد count را از موجودی کم میکند. (در صورتی که موبایل با 
مشخصات وارد شده یافت نشد، پیغام مناسب چاپ شود)
