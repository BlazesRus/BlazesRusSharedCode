using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace CSharpSharedCode.ExperimentalCode
{
    //Based on http://www.devcurry.com/2010/08/creating-and-loading-xaml-dynamically.html
    /// <summary>
    /// 
    /// </summary>
    class XAMLLoader//: Window
    {
        private void CreateExampleXAML(object sender, RoutedEventArgs e)
        {
            try
            {
                Grid grd = new Grid();
                grd.Height = 210;
                grd.Width = 400;

                Button btn = new Button();
                btn.Height = 50;
                btn.Width = 80;
                btn.Content = "Button";
                btn.Background = new SolidColorBrush(Colors.Red);
                btn.Margin = new Thickness(5, 5, 310, 120);
                grd.Children.Add(btn);

                TextBox txt = new TextBox();
                txt.Height = 50;
                txt.Width = 100;
                txt.Text = "TextBox";
                txt.Foreground = new SolidColorBrush(Colors.Red);
                txt.Margin = new Thickness(5, 60, 310, 80);
                grd.Children.Add(txt);

                //Store this Xaml in File

                FileStream Fs = new FileStream(@"GeneratedXAML.Xaml", FileMode.CreateNew);
                System.Windows.Markup.XamlWriter.Save(grd, Fs);
                Fs.Close();

            }
            catch (Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.ToString());
            }
        }
        private void LoadExampleXAML(object sender, RoutedEventArgs e)//,Grid XAMLGrid
        {
            try
            {
                System.Windows.Forms.OpenFileDialog Fd = new System.Windows.Forms.OpenFileDialog();
                Fd.ShowDialog();
                string LoadedFileName = Fd.FileName;

                //Load the file
                FileStream Fs = new FileStream(@LoadedFileName, FileMode.Open);
                Grid grdToLoad = new Grid();
                grdToLoad.Height = 210;
                grdToLoad.Width = 400;


//            this.Content.GetType().ToString(); //Get Paneltype used
                grdToLoad = System.Windows.Markup.XamlReader.Load(Fs) as Grid;
                XAMLGrid.Children.Add(grdToLoad);

                Fs.Close();
            }
            catch (Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.ToString());
            }
        }
    }
}
