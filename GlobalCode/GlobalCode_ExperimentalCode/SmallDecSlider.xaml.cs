using CSharpGlobalCode.GlobalCode_ExperimentalCode;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
//Range slider code based mostly on
//http://stackoverflow.com/questions/36545896/universal-windows-uwp-range-slider

	/// <summary>
	/// Interaction logic for SmallDecSlider.xaml
	/// </summary>
	public sealed partial class SmallDecSlider : UserControl
	{
		public SmallDec Minimum
		{
			get { return (SmallDec)GetValue(MinimumProperty); }
			set { SetValue(MinimumProperty, value); }
		}

		public SmallDec Maximum
		{
			get { return (SmallDec)GetValue(MaximumProperty); }
			set { SetValue(MaximumProperty, value); }
		}

		public SmallDec Value
		{
			get { return (SmallDec)GetValue(ValueProperty); }
			set { SetValue(ValueProperty, value); }
		}

		public static readonly DependencyProperty MinimumProperty = DependencyProperty.Register("Minimum", typeof(SmallDec), typeof(SmallDecSlider), new PropertyMetadata(0.0));

		public static readonly DependencyProperty MaximumProperty = DependencyProperty.Register("Maximum", typeof(SmallDec), typeof(SmallDecSlider), new PropertyMetadata(1.0));

		public static readonly DependencyProperty ValueProperty = DependencyProperty.Register("Value", typeof(SmallDec), typeof(SmallDecSlider), new PropertyMetadata(0.0, OnValuePropertyChanged));

		public SmallDecSlider()
		{
			this.InitializeComponent();
		}

		private static void OnValuePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			var slider = (SmallDecSlider)d;
			var newValue = (SmallDec)e.NewValue;

			if (newValue < slider.Minimum)
			{
				slider.Value = slider.Minimum;
			}
			else if (newValue > slider.Maximum)
			{
				slider.Value = slider.Maximum;
			}
			else
			{
				slider.Value = newValue;
			}

			slider.UpdateThumb(slider.Value);
		}

		public void UpdateThumb(SmallDec value, bool update = false)
		{
			if (ContainerCanvas != null)
			{
				if (update || !Thumb.IsDragging)
				{
					var relativeLeft = ((value - Minimum) / (Maximum - Minimum)) * ContainerCanvas.ActualWidth;

					Canvas.SetLeft(Thumb, (double)relativeLeft);
					Canvas.SetLeft(ActiveRectangle, (double)relativeLeft);

					ActiveRectangle.Width = (double)((Maximum - value) / (Maximum - Minimum) * ContainerCanvas.ActualWidth);
				}
			}
		}

		private void ContainerCanvas_SizeChanged(object sender, SizeChangedEventArgs e)
		{
			var relativeLeft = ((Value - Minimum) / (Maximum - Minimum)) * ContainerCanvas.ActualWidth;
			var relativeRight = ContainerCanvas.ActualWidth;

			Canvas.SetLeft(Thumb, (double)relativeLeft);
			Canvas.SetLeft(ActiveRectangle, (double)relativeLeft);

			ActiveRectangle.Width = (double)((Maximum - Value) / (Maximum - Minimum) * ContainerCanvas.ActualWidth);
		}

		private void Thumb_DragDelta(object sender, DragDeltaEventArgs e)
		{
			var min = DragThumb(Thumb, SmallDec.Zero(), Maximum, e.HorizontalChange);
			UpdateThumb(min, true);
			Value = min.Round();
		}

		private SmallDec DragThumb(Thumb thumb, SmallDec min, SmallDec max, double offset)
		{
			var currentPos = Canvas.GetLeft(thumb);
			SmallDec nextPos = (SmallDec) currentPos + offset;

			nextPos = SmallDec.Max(min, nextPos);
			nextPos = SmallDec.Min(max, nextPos);

			return (Minimum + (nextPos / ContainerCanvas.ActualWidth) * (Maximum - Minimum));
		}

		private void Thumb_DragCompleted(object sender, DragCompletedEventArgs e)
		{
			UpdateThumb(Value);
			Canvas.SetZIndex(Thumb, 10);
		}
	}
}
