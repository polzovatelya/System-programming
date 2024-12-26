namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.thread_info = new System.Windows.Forms.Label();
            this.btn_threads = new System.Windows.Forms.Button();
            this.image1 = new System.Windows.Forms.PictureBox();
            this.image2 = new System.Windows.Forms.PictureBox();
            this.present = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.image1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.image2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.present)).BeginInit();
            this.SuspendLayout();
            // 
            // thread_info
            // 
            this.thread_info.AutoSize = true;
            this.thread_info.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.thread_info.Location = new System.Drawing.Point(170, 376);
            this.thread_info.MaximumSize = new System.Drawing.Size(300, 200);
            this.thread_info.MinimumSize = new System.Drawing.Size(300, 100);
            this.thread_info.Name = "thread_info";
            this.thread_info.Size = new System.Drawing.Size(300, 100);
            this.thread_info.TabIndex = 0;
            this.thread_info.Click += new System.EventHandler(this.thread_info_Click);
            // 
            // btn_threads
            // 
            this.btn_threads.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(72)))), ((int)(((byte)(201)))), ((int)(((byte)(132)))));
            this.btn_threads.Location = new System.Drawing.Point(12, 376);
            this.btn_threads.Name = "btn_threads";
            this.btn_threads.Size = new System.Drawing.Size(152, 54);
            this.btn_threads.TabIndex = 1;
            this.btn_threads.Text = "Пуск";
            this.btn_threads.UseVisualStyleBackColor = false;
            this.btn_threads.Click += new System.EventHandler(this.btn_threads_Click);
            // 
            // image1
            // 
            this.image1.Location = new System.Drawing.Point(12, 12);
            this.image1.Name = "image1";
            this.image1.Size = new System.Drawing.Size(423, 358);
            this.image1.TabIndex = 2;
            this.image1.TabStop = false;
            // 
            // image2
            // 
            this.image2.Location = new System.Drawing.Point(451, 16);
            this.image2.Name = "image2";
            this.image2.Size = new System.Drawing.Size(487, 354);
            this.image2.TabIndex = 3;
            this.image2.TabStop = false;
            // 
            // present
            // 
            this.present.BackColor = System.Drawing.SystemColors.Info;
            this.present.Location = new System.Drawing.Point(488, 376);
            this.present.Name = "present";
            this.present.Size = new System.Drawing.Size(487, 276);
            this.present.TabIndex = 4;
            this.present.TabStop = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(169, 505);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 21);
            this.label1.TabIndex = 5;
            this.label1.Text = "Поток1";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(170, 547);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(59, 21);
            this.label2.TabIndex = 6;
            this.label2.Text = "Поток 2";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(171, 588);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(56, 21);
            this.label3.TabIndex = 7;
            this.label3.Text = "Поток3";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(987, 664);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.present);
            this.Controls.Add(this.image2);
            this.Controls.Add(this.image1);
            this.Controls.Add(this.btn_threads);
            this.Controls.Add(this.thread_info);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.image1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.image2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.present)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label thread_info;
        private System.Windows.Forms.Button btn_threads;
        private System.Windows.Forms.PictureBox image1;
        private System.Windows.Forms.PictureBox image2;
        private System.Windows.Forms.PictureBox present;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
    }
}

