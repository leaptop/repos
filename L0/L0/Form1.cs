using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace L0
{
    public partial class Form1 : Form
    {
        public int n;
        public int m;
        int[,] mas;
        public Form1()
        {
            InitializeComponent();
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("ФИО: Алексеев С.В. \nГруппа:ИП-712");
        }

        public string[] elems = new string[18];

        private void button1_Click(object sender, EventArgs e)
        {
            elems[0] = "a"; elems[1] = "b"; elems[2] = "c"; elems[3] = "d"; elems[4] = "e"; elems[5] = "f";
            elems[6] = "g"; elems[7] = "h"; elems[8] = "i"; elems[9] = "j"; elems[10] = "k"; elems[11] = "l";
            elems[12] = "m"; elems[13] = "n"; elems[14] = "o"; elems[15] = "p"; elems[16] = "q"; elems[17] = "r";
            n = Convert.ToInt32(numericUpDown1.Value);

            Random rand = new Random();
            if (n != 0)
            {
                dataGridView1.RowCount = n;
                dataGridView1.ColumnCount = n;
                dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;

                mas = new int[n, n];
                int i, j;
                for (i = 0; i < n; ++i)
                {
                    dataGridView1.Rows[i].HeaderCell.Value = elems[i].ToString();
                    for (j = 0; j < n; ++j)
                    {
                        dataGridView1.Columns[j].HeaderCell.Value = elems[j].ToString();//называю хедеры колонок(столбцов) именами elems
                        mas[i, j] = rand.Next(2);
                        dataGridView1.Rows[i].Cells[j].Value = mas[i, j];

                    }
                }

                button2.Enabled = true;
                maxToolStripMenuItem.Enabled = true;
            }
            else
            {
                MessageBox.Show("N и M не могут быть нулевыми");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int[] masLocal = new int[n];
            int max = 0;
            int i, j;
            for (i = 0; i < n; ++i)
            {
                for (j = 0; j < n; ++j)
                {
                    try
                    {
                        max = Convert.ToInt32(dataGridView1.Rows[i].Cells[j].Value);
                        masLocal[i] = Convert.ToInt32(dataGridView1.Rows[i].Cells[0].Value);
                    }
                    catch (Exception ee)
                    {
                        MessageBox.Show("Значения ячеек м.б. только 1 и 0.\n" +
                            "Проверьте ячейку [" + i + "][" + j + "] (" + elems[i] + ", " + elems[j] + ")", "неверный ввод",
     MessageBoxButtons.OK, MessageBoxIcon.Error); return;
                    }

                    if (max != 0 && max != 1)
                    {
                        MessageBox.Show("Значения ячеек м.б. только 1 и 0.\n В ячейке[" + i + "][" + j +
                            "]  (" + elems[i] + ", " + elems[j] + ")" +
                            "установлено: " + max, "неверный ввод",
                         MessageBoxButtons.OK, MessageBoxIcon.Error); return;
                    }
                    if (max > masLocal[i])
                        masLocal[i] = max;
                }
            }
            dataGridView2.RowCount = n;
            dataGridView2.ColumnCount = 1;
            for (i = 0; i < n; ++i)
                dataGridView2.Rows[i].Cells[0].Value = masLocal[i];
            button2.Enabled = true;
            maxToolStripMenuItem.Enabled = true;//стрип меню - главное меню
        }
        private void button3_Click(object sender, EventArgs e)
        {
            int i = 0, j = 0;
            int[] arrCmp = new int[n];

            for (i = 0; i < n; ++i)
            {
                for (j = 0; j < n; ++j)
                {//двойная некрасивая проверка на правильность матрицы бинарного отношения
                    try
                    {
                        mas[i, j] = Convert.ToInt32(dataGridView1.Rows[i].Cells[j].Value);
                    }
                    catch (Exception ee)
                    {
                        MessageBox.Show("Значения ячеек м.б. только 1 и 0.\n" +
                            "Проверьте ячейку [" + i + "][" + j + "] (" + elems[i] + ", " + elems[j] + ")", "неверный ввод",
     MessageBoxButtons.OK, MessageBoxIcon.Error); return;
                    }

                    if (mas[i, j] != 0 && mas[i, j] != 1)
                    {
                        MessageBox.Show("Значения ячеек м.б. только 1 и 0.\n В ячейке[" + i + "][" + j +
                            "]  (" + elems[i] + ", " + elems[j] + ")" +
                            "установлено: " + mas[i, j], "неверный ввод",
                         MessageBoxButtons.OK, MessageBoxIcon.Error); return;
                    }
                }
            }
            reflexivityCheck();
            antireflexivityCheck();
            symmetryCheck();
        }
        public void reflexivityCheck()
        {
            int cmp = 1;
            for (int i = 0; i < n; i++) { cmp *= mas[i, i]; }
            if (cmp == 1) textBox1.Text = "Отношение рефлексивно, т.к главаная диагональ состоит из единиц";
            else textBox1.Text = "Отношение нерефлексивно, т.к главная диагональ не состоит из единиц";
            button3.Enabled = true;
        }
        public void antireflexivityCheck()
        {
            int cmp = 0;
            for(int i = 0; i<n; i++)
            {
                cmp += mas[i, i];
                if (cmp == 0) textBox2.Text = "Отношение антирефлексивно, т.к. главная диагональ состоит из нулей";
                else textBox2.Text = "Отношение не антирефлексивно, т.к главная диагональ не состоит из нулей";
            }
        }
       public void symmetryCheck()
        {
            int i = 0, j = 0;
            for (i = 0; i < n; i++) 
                for(j = 0; j<n; j++)
                {
                    if (mas[i, j] != mas[j, i])
                    {
                        textBox3.Text = "Отношение не симметрично, т.к. (" + elems[i] + ", " + elems[j] +
                            ") не равно (" + elems[j] + ", " + elems[i] + ")";
                        return;
                    }
                    else continue;
                }
            textBox3.Text = "Отношение симметрично, т.к. элементы матрицы симметричны относительно главной диагонали";
        }

        private void sizeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 f = new Form2();
            f.Owner = this;
            f.ShowDialog();
        }

        private void dataGridView1_CellValuePushed(object sender, DataGridViewCellValueEventArgs e)
        {//здесь происходит интерактивное изменеие ячеек... нет... эта штука пока не реагирует
         /* int j = e.ColumnIndex;
          int i = e.RowIndex;
          int value = Convert.ToInt32(e.ToString());
          if (value == 0 || value == 1)
              mas[i, j] = value;
          else
          {
              MessageBox.Show("your message",
 "window title",
 MessageBoxButtons.OK,
 MessageBoxIcon.Warning // for Warning  
                        //MessageBoxIcon.Error // for Error 
                        //MessageBoxIcon.Information  // for Information
                        //MessageBoxIcon.Question // for Question
);
          }*/
        }
        public void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {

        }
        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }
        private void dataGridView1_CellValueChanged(object sender, DataGridViewCellEventArgs e)
        {//этот метод - не то, что нужно  

        }
        public void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }
        private void startToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        private void label1_Click(object sender, EventArgs e)
        {

        }
        private void label2_Click(object sender, EventArgs e)
        {

        }
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        private void toolStripTextBox1_Click(object sender, EventArgs e)
        {

        }


    }
}
