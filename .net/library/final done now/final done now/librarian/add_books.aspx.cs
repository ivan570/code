using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

namespace final_done_now.librarian
{
    public partial class add_books : System.Web.UI.Page
    {
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename='D:\code\.net\library\final done now\final done now\App_Data\lms.mdf';Integrated Security=True");
        protected void Page_Load(object sender, EventArgs e)
        {
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
        }

        protected void b1_Click(object sender, EventArgs e)
        {
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }

            string books_image_name = f1.FileName.ToString();
            string path1 = "";
            f1.SaveAs(Request.PhysicalApplicationPath + "/librarian/books_images/" + books_image_name.ToString());
            path1 = "books_images/" + books_image_name.ToString();
            string path3 = "";
            string path2 = "";
            if (f2.FileName.ToString() != "")
            {
                string books_pdf_name = f2.FileName.ToString();
                f1.SaveAs(Request.PhysicalApplicationPath + "/librarian/books_pdf/" + books_pdf_name.ToString());
                path2 = "books_pdf/" + books_pdf_name.ToString();
            }
            if (f3.FileName.ToString() != "")
            {
                string books_video_name = f3.FileName.ToString();
                
                f1.SaveAs(Request.PhysicalApplicationPath + "/librarian/books_video/" + books_video_name.ToString());
                path3 = "books_video/" + books_video_name.ToString();
            }
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "insert into ibooks values('" + bookstitle.Text + "', '" + path1.ToString() + "', '" + path2.ToString() + "', '" + path3.ToString() + "', '"
                + authorname.Text + "', '" + isbn.Text + "', '" + qty.Text + "')";
            cmd.ExecuteNonQuery();

            msg.Style.Add("display", "block");
        }
    }
}