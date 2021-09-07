// ***********************************************************************
// Assembly         : BlazesCSharpSharedCode
// Author           : BlazesRus
// Created          : 05-11-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 05-11-2018
// ***********************************************************************
// <copyright file="FileAccessCommands.cs" company="">
//     Copyright ©  2018
// </copyright>
// <summary></summary>
// ***********************************************************************
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpSharedCode.GlobalMiscCode
{
	/// <summary>
	/// Class FileAccessCommands.
	/// </summary>
	public static class FileAccessCommands
    {
		/// <summary>
		/// This is the same default buffer size as
		/// <see cref="StreamReader" /> and <see cref="FileStream" />.
		/// </summary>
		private const int DefaultBufferSize = 4096;

		/// <summary>
		/// Indicates that
		/// 1. The file is to be used for asynchronous reading.
		/// 2. The file is to be accessed sequentially from beginning to end.
		/// </summary>
		private const FileOptions DefaultOptions = FileOptions.Asynchronous | FileOptions.SequentialScan;

		/// <summary>
		/// Reads all lines asynchronous.
		/// </summary>
		/// <param name="path">The path.</param>
		/// <returns>Task&lt;System.String[]&gt;.</returns>
		public static Task<string[]> ReadAllLinesAsync(string path)
        {
            return ReadAllLinesAsync(path, Encoding.UTF8);
        }

		/// <summary>
		/// read all lines as an asynchronous operation.
		/// </summary>
		/// <param name="path">The path.</param>
		/// <param name="encoding">The encoding.</param>
		/// <returns>Task&lt;System.String[]&gt;.</returns>
		public static async Task<string[]> ReadAllLinesAsync(string path, Encoding encoding)
        {
            var lines = new List<string>();

            // Open the FileStream with the same FileMode, FileAccess
            // and FileShare as a call to File.OpenText would've done.
            using (var stream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.Read, DefaultBufferSize, DefaultOptions))
            using (var reader = new StreamReader(stream, encoding))
            {
                string line;
                while ((line = await reader.ReadLineAsync()) != null)
                {
                    lines.Add(line);
                }
            }

            return lines.ToArray();
        }


		/// <summary>
		/// Reads the file contents as list asynchronous.
		/// </summary>
		/// <param name="path">The path.</param>
		/// <returns>Task&lt;List&lt;System.String&gt;&gt;.</returns>
		public static Task<List<string>> ReadFileContentsAsListAsync(string path)
        {
            return ReturnFileContentsAsListAsync(path, Encoding.UTF8);
        }

		/// <summary>
		/// Returns the file contents as list asynchronously.
		/// </summary>
		/// <param name="path">The path.</param>
		/// <param name="encoding">The encoding.</param>
		/// <returns>Task&lt;List&lt;System.String&gt;&gt;.</returns>
		public static async Task<List<string>> ReturnFileContentsAsListAsync(string path, Encoding encoding)
        {
            var lines = new List<string>();

            // Open the FileStream with the same FileMode, FileAccess
            // and FileShare as a call to File.OpenText would've done.
            using (var stream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.Read, DefaultBufferSize, DefaultOptions))
            using (var reader = new StreamReader(stream, encoding))
            {
                string line;
                while ((line = await reader.ReadLineAsync()) != null)
                {
                    lines.Add(line);
                }
            }

            return lines;
        }

		/// <summary>
		/// Returns the file contents as list with default encoding of UTF8
		/// </summary>
		/// <param name="path">The path.</param>
		/// <returns>List&lt;System.String&gt;.</returns>
		public static List<string> ReturnFileContentsAsList(string path)
        {
            return ReturnFileContentsAsList(path, Encoding.UTF8);
        }

		/// <summary>
		/// Returns the file contents as list.
		/// </summary>
		/// <param name="path">The path.</param>
		/// <param name="encoding">The encoding.</param>
		/// <returns>List&lt;System.String&gt;.</returns>
		public static List<string> ReturnFileContentsAsList(string path, Encoding encoding)
        {
            var lines = new List<string>();

            // Open the FileStream with the same FileMode, FileAccess
            // and FileShare as a call to File.OpenText would've done.
            using (var stream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.Read, DefaultBufferSize, DefaultOptions))
            using (var reader = new StreamReader(stream, encoding))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    lines.Add(line);
                }
            }

            return lines;
        }

		/// <summary>
		/// Clears file, then Writes the text asynchronous into file (Based from https://stackoverflow.com/questions/11774827/writing-to-a-file-asynchronously)
		/// </summary>
		/// <param name="filePath">The file path.</param>
		/// <param name="text">The text.</param>
		/// <returns>Task.</returns>
		public static async Task WriteFileAsync(string filePath, string text)
        {
            byte[] encodedText = Encoding.ASCII.GetBytes(text);//ASCII instead of Unicode to prevent placing null after each character(https://stackoverflow.com/questions/14181866/converting-string-to-byte-creates-zero-character)

            using (FileStream sourceStream = new FileStream(filePath, FileMode.Truncate, FileAccess.Write, FileShare.None, bufferSize: 4096, useAsync: true))
            {
                await sourceStream.WriteAsync(encodedText, 0, encodedText.Length);
            };
        }

		/// <summary>
		/// Create new file, then writes the text asynchronous into file (Based from https://stackoverflow.com/questions/11774827/writing-to-a-file-asynchronously)
		/// </summary>
		/// <param name="filePath">The file path.</param>
		/// <param name="text">The text.</param>
		/// <returns>Task.</returns>
		public static async Task WriteNewFileAsync(string filePath, string text)
        {
            byte[] encodedText = Encoding.ASCII.GetBytes(text);//ASCII instead of Unicode to prevent placing null after each character(https://stackoverflow.com/questions/14181866/converting-string-to-byte-creates-zero-character)

            using (FileStream sourceStream = new FileStream(filePath, FileMode.CreateNew, FileAccess.Write, FileShare.None, bufferSize: 4096, useAsync: true))
            {
                await sourceStream.WriteAsync(encodedText, 0, encodedText.Length);
            };
        }

		/// <summary>
		/// Gets the List of files from directory asynchronously.
		/// </summary>
		/// <param name="DirectoryPath">The directory path.</param>
		/// <returns>Task&lt;List&lt;System.String&gt;&gt;.</returns>
		public static async Task<List<string>> GetFileListFromDirectoryAsync(string DirectoryPath)
        {
            //SLightly async version of Getting files from http://writeasync.net/?p=2621
            // Avoid blocking the caller for the initial enumerate call.
            await Task.Yield();
            List<string> FileList = new List<string>();
            if (Directory.Exists(DirectoryPath))
            {
                foreach (string file in Directory.EnumerateFiles(DirectoryPath))
                {
                    FileList.Add(file);
                }
            }
            //else
            //{//Create Directory if doesn't exist
            //    Directory.CreateDirectory(StatTrackingSavePath);
            //}
            return FileList;
        }
    }
}
