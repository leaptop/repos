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
            }
            else
            {
                MessageBox.Show("N не может быть нулевым");
            }
            //запрещает сортировать содержимое столбцов кликом по хедеру, а также минимизирует длину ячеек:
            dataGridView1.Columns.Cast<DataGridViewColumn>().ToList().ForEach(f => f.SortMode = DataGridViewColumnSortMode.NotSortable);
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
            antySymmetryCheck();
            transitivityCheck();
        }
        public void reflexivityCheck()
        {
            int cmp = 1;
            for (int i = 0; i < n; i++) { cmp *= mas[i, i]; }
            if (cmp == 1) textBox1.Text = "Отношение рефлексивно, т.к главаная диагональ состоит из единиц";
            else textBox1.Text = "Отношение не рефлексивно, т.к главная диагональ не состоит из единиц";
            button3.Enabled = true;
        }
        public void antireflexivityCheck()
        {
            int cmp = 0;
            for (int i = 0; i < n; i++)
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
                for (j = 0; j < n; j++)
                {
                    if (mas[i, j] != mas[j, i])
                    {
                        textBox3.Text = "Отношение не симметрично, т.к. (" + elems[i] + ", " + elems[j] +
                            ") не равно (" + elems[j] + ", " + elems[i] + ")";
                        return;
                    }
                    else continue;
                }
            textBox3.Text = "Отношение симметрично, т.к. все симметричные относительно главной диагонали элементы матрицы равны";
        }
        public void antySymmetryCheck()
        {
            int i = 0, j = 0;
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                {
                    if (i == j) continue;
                    if ((mas[i, j] == mas[j, i]) && mas[i, j] != 0)
                    {
                        textBox4.Text = "Отношение не антисимметрично, т.к. (" + elems[i] + ", " + elems[j] +
                            ") равно (" + elems[j] + ", " + elems[i] + ")";
                        return;
                    }
                    else continue;
                }
            textBox4.Text = "Отношение антисимметрично, т.к. все единичные элементы преобразованием симметрии относительно главной диагонали переходят в нули";
        }
        public void transitivityCheck()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (i != j && j != k && i != k && 
                            !(mas[i, j] == 1 && mas[j, k] == 1 && mas[i, k] == 1)) textBox5.Text =
                              "Отношение не тразитивно, т.к. нет транзита (" + elems[i] + ", " + elems[j] + ")(" + elems[j] + ", " + elems[k] + ")(" + elems[i] + ", " + elems[k] + ")";
                    }
                }
            }
            /*status := True;
for i := 1 to size do
  for j := 1 to size do
    for k := 1 to size do
      if (tr[i,j] <> 1) and (tr[j,k] <> 1) and (tr[i,k] <> 1) then status := False;*/
        }

        private void sizeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 f = new Form2();
            f.Owner = this;
            f.ShowDialog();
        }
    }
}
