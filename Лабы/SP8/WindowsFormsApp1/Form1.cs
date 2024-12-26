using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.Mime.MediaTypeNames;
using System.Management;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        Thread main_th; //Главный поток

        //Создание ещё 3-х потоков
        Thread t1;
        Thread t2;
        Thread t3;

        // значение может быть присвоено только раз, во время объявления
        // Секудомеры для двух потоков
        readonly Stopwatch image_1_stopwatch = new Stopwatch();
        readonly Stopwatch image_2_stopwatch = new Stopwatch();
        readonly Stopwatch image_3_stopwatch = new Stopwatch();

        //Промежуток времени 
        TimeSpan image_1_timespan;
        TimeSpan image_2_timespan;
        TimeSpan image_3_timespan;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void thread_info_Click(object sender, EventArgs e)
        {

        }

        private void btn_threads_Click(object sender, EventArgs e)
        {
            main_th = Thread.CurrentThread;
            main_th.Name = "main";
            thread_info.Text = "Имя домена: " + Thread.GetDomain().FriendlyName +
                "\nИмя потока: " + main_th.Name +
                "\nСостояние потока: " + main_th.ThreadState.ToString() +
                "\nУровень приоритета: " + main_th.Priority.ToString() +
                "\nПоток существует: " + main_th.IsAlive.ToString();

            t1 = new Thread(random_img1);
            t2 = new Thread(random_img2);
            t3 = new Thread(show_system_info);

            t1.Start();
            t2.Start();
            t3.Start();
            
             

            t3.Join(); 
            label1.Text = "Поток 1: " +String.Format("{0:00}:{1:00}:{2:00}.{3:00}",
                image_1_timespan.Hours,
                image_1_timespan.Minutes, image_1_timespan.Seconds,
                image_1_timespan.Milliseconds);
            label2.Text = "Поток 2: " + String.Format("{0:00}:{1:00}:{2:00}.{3:00}",
                image_2_timespan.Hours,
                image_2_timespan.Minutes, image_1_timespan.Seconds,
                image_2_timespan.Milliseconds);
            label3.Text = "Поток 3: " + String.Format("{0:00}:{1:00}:{2:00}.{3:00}",
                image_3_timespan.Hours,
                image_3_timespan.Minutes, image_1_timespan.Seconds,
                image_3_timespan.Milliseconds);




        }

        Bitmap GetBitmapRegion(Rectangle rect, Bitmap bmp)
        {
            Bitmap region = new Bitmap(rect.Width, rect.Height);
            using (Graphics g = Graphics.FromImage(region))
            {
                g.DrawImage(bmp, new Rectangle(0, 0, rect.Width, rect.Height), rect, GraphicsUnit.Pixel);
            }
            return region;
        }
        public void random_img1()
        {
            // Включаем замер времени
            image_1_stopwatch.Start();
            

            // Создаем список из структуры (битмап - номер ячейки в пазле)
            List<Tuple<Bitmap, int>> list_image_parts = new List<Tuple<Bitmap, int>>();

            // Загружаем картинку
            Bitmap bitmap = new Bitmap(@"C:\Users\gagag\Desktop\3 курс\Системное программирование 2024\Лабы\SP8\WindowsFormsApp1\daman.png");

            Graphics DC = image1.CreateGraphics();
            

            // Номер ячейки
            int cell_number = 0;
            // Цикл по двум строкам
            for (int i = 0; i < 2; i++)
            {
                // Начальая и конечная у-координаты ячейки
                int y_begin = i * (bitmap.Height / 2);
                int y_end = i * (bitmap.Height / 2) + (bitmap.Height / 2);

                // Начальая и конечная х-координаты ячейки
                int x_begin = 0;
                int x_end = (bitmap.Width / 2);
                
                // Цикл по 2 столбцам
                for (int j = 0; j <= 1; j++)
                {
                    // Получаем прямоугольник (ячейку в матрице)
                    Rectangle rect = new Rectangle(x_begin, y_begin, x_end - x_begin, y_end - y_begin);

                    // Получаем регион битмапа по в этом прямоугольнике
                    Bitmap buffer = GetBitmapRegion(rect, bitmap);

                    // Составляем структуру битмап-номер ячейки
                    var image_part = new Tuple<Bitmap, int>(buffer, cell_number);

                    // Добавляем в список
                    list_image_parts.Add(image_part);
                    x_begin += (bitmap.Width / 2);
                    x_end += (bitmap.Width / 2);


                    cell_number++;
                }
            }

            // Флаг, ассоциирующий собранность картинки
            bool isAssembled = false;
            while (!isAssembled)
            {
                isAssembled = true;
                Random random = new Random();

                // Перемешиваем ячейки
                for (int i = 3; i >= 1; i--)
                {
                    int num = random.Next(i + 1);
                    var rand_image_part = list_image_parts[num];
                    list_image_parts[num] = list_image_parts[i];

                    list_image_parts[i] = rand_image_part;
                }
                // Выводим перемешанные ячейки на экран
                cell_number = 0;
                int fragmentWidth = bitmap.Width / 2;
                int fragmentHeight = bitmap.Height / 2;

                for (int i = 0; i < 2; i++)
                {
                    int y_begin = i * fragmentHeight;
                    for (int j = 0; j < 2; j++)
                    {
                        int x_begin = j * fragmentWidth;
                        DC.DrawImage(list_image_parts[cell_number].Item1, x_begin, y_begin, fragmentWidth, fragmentHeight); // Изменение здесь
                        cell_number++;
                    }
                }
                // Проверяем собранность
                for (int i = 0; i < 4; i++)
                {
                    if (list_image_parts[i].Item2 != i)
                    {
                        isAssembled = false;
                        break;
                    }
                }
                // Если собралось - завершаем процедуру
                if (isAssembled)
                {
                    image_1_stopwatch.Stop();
                    image_1_timespan = image_1_stopwatch.Elapsed;
                    return;
                }
            }
        }


        public void random_img2()
        {
            // Включаем замер времени
            image_2_stopwatch.Start();
            // Создаем список из структуры (битмап - номер ячейки в пазле)
            List<Tuple<Bitmap, int>> list_image_parts = new List<Tuple<Bitmap, int>>();

            // Загружаем картинку
            Bitmap bitmap = new Bitmap(@"C:\Users\gagag\Desktop\3 курс\Системное программирование 2024\Лабы\SP8\WindowsFormsApp1\binto.png");

            Graphics DC = image2.CreateGraphics();
            // Номер ячейки
            int cell_number = 0;
            // Цикл по 6 строкам
            for (int i = 0; i < 6; i++)
            {
                // Начальая и конечная х-координаты ячейки
                int x_begin = 0;
                int x_end = bitmap.Width;
                // Начальая и конечная у-координаты ячейки
                int y_begin = i * (bitmap.Height / 6);
                int y_end = i * (bitmap.Height / 6) + (bitmap.Height / 6);
                // Получаем прямоугольник (ячейку в матрице)
                Rectangle rect = new Rectangle(x_begin, y_begin, x_end -
                x_begin, y_end - y_begin);

                // Получаем регион битмапа в этом прямоугольнике
                Bitmap buffer = GetBitmapRegion(rect, bitmap);
                // Составляем структуру битмап-номер ячейки
                var image_part = new Tuple<Bitmap, int>(buffer,

                cell_number);

                // Добавляем в список
                list_image_parts.Add(image_part);
                y_begin += (bitmap.Height / 6);
                y_end += (bitmap.Height / 6);
                cell_number++;
            }
            // Флаг, ассоциирующий собранность картинки
            bool isAssembled = false;
            while (!isAssembled)
            {
                isAssembled = true;
                Random random = new Random();
                // Перемешиваем ячейки
                for (int i = 5; i >= 1; i--)
                {
                    int num = random.Next(i + 1);
                    var rand_image_part = list_image_parts[num];
                    list_image_parts[num] = list_image_parts[i];
                    list_image_parts[i] = rand_image_part;
                }
                // Выводим перемешанные ячейки на экран
                cell_number = 0;
                for (int i = 0; i < 6; i++)
                {
                    // Начальая и конечная х-координаты ячейки
                    int x_begin = 0;
                    int x_end = bitmap.Width;
                    // Начальая и конечная у-координаты ячейки
                    int y_begin = i * (bitmap.Height / 6);
                    int y_end = i * (bitmap.Height / 6) + (bitmap.Height /
                    6);
                    DC.DrawImage(list_image_parts[cell_number].Item1,
                    x_begin, y_begin, x_end - x_begin, y_end - y_begin);

                    x_begin += (bitmap.Width / 6);
                    x_end += (bitmap.Width / 6);
                    cell_number++;
                }
                // Проверяем собранность
                for (int i = 0; i < 6; i++)
                {
                    if (list_image_parts[i].Item2 != i)
                    {
                        isAssembled = false;
                        break;
                    }
                }
                // Если собралось - завершаем процедуру
                if (isAssembled)

                {
                    image_2_stopwatch.Stop();
                    image_2_timespan = image_2_stopwatch.Elapsed;
                    return;
                }
            }
        }

        public void show_system_info()
        {
            image_3_stopwatch.Start();
            var info = new StringBuilder();
            // 1. Из функций Windows:
            info.AppendFormat("Из функций Windows\n");
            info.AppendFormat($"Пользователь: {Environment.UserName} \n");
            info.AppendFormat($"Путь: {Environment.CurrentDirectory}\n");
            info.AppendFormat("Версия Windows: {0}\n",Environment.OSVersion);
            info.AppendFormat("Число процессоров: {0}\n", Environment.ProcessorCount);
            info.AppendFormat("Использованная память: {0}\n", Environment.WorkingSet);


            // 2. Из реестра:

            using (RegistryKey key = Registry.LocalMachine.OpenSubKey(@"SOFTWARE\Microsoft\Windows NT\CurrentVersion"))
            {
                ///object installDateObj = key.GetValue("InstallDate");
                ///long installDateTicks = 0; // Инициализация
                ///DateTime installDate = new DateTime(1601, 1, 1, 0, 0, 0, DateTimeKind.Utc).AddSeconds(installDateTicks);
                info.AppendFormat("\nИз реестра\n");
                info.AppendFormat($"Системный каталог: {key.GetValue("SystemRoot")}\n");
                info.AppendFormat($"Название продукта: {key.GetValue("ProductName")}\n");
            }

            // 3. Из программного окружения (WMI):
            using (var searcher = new ManagementObjectSearcher("SELECT * FROM Win32_ComputerSystem"))
            {
                foreach (ManagementObject obj in searcher.Get())
                {

                    info.AppendFormat("\nИз Программного окружения\n");
                    info.AppendFormat($"Производитель: {obj["Manufacturer"]}\n");
                    info.AppendFormat($"Модель: {obj["Model"]} \n");
                    info.AppendFormat($"Тип системы: {obj["SystemType"]}\n");
                }
            }

            t1.Join();
            t2.Join();
            Graphics DC = present.CreateGraphics();
            DC.DrawString(info.ToString(), new Font("Franklin Gothic Medium Cond", 8),Brushes.Black, 3, 3);
            image_3_stopwatch.Stop();
            image_3_timespan = image_3_stopwatch.Elapsed;

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}


