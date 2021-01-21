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
    public partial class edit_books : System.Web.UI.Page
    {
        int id;
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename='D:\code\.net\library\final done now\final done now\App_Data\lms.mdf';Integrated Security=True");
        protected void Page_Load(object sender, EventArgs e)
        {
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            if (Session["librarian"] == null)
            {
                Response.Redirect("login.aspx");
            }
            id = Convert.ToInt32(Request.QueryString["id"].ToString());

            if (IsPostBack)
                return;

            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from ibooks where id=" + id + "";
            cmd.ExecuteNonQuery();
            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);

            foreach (DataRow dr in dt.Rows)
            {
                bookstitle.Text = dr["books_title"].ToString();
                authorname.Text = dr["books_author_name"].ToString();
                isbn.Text = dr["books_isbn"].ToString();
                qty.Text = dr["available_qty"].ToString();
                booksimage.Text = dr["books_image"].ToString();
                bookspdf.Text = dr["books_pdf"].ToString();
                booksvideo.Text = dr["books_video"].ToString();
            }
        }

        protected void b1_Click(object sender, EventArgs e)
        {
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }

            string books_image_name;
            string path1 = "";
            
            string path3 = "";
            string path2 = "";

            if(f1.FileName.ToString() != "")
            {
                books_image_name = f1.FileName.ToString();
                f1.SaveAs(Request.PhysicalApplicationPath + "/librarian/books_images/" + books_image_name.ToString());
                path1 = "books_images/" + books_image_name.ToString();

                SqlCommand cmd = con.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "update ibooks set books_title='"+bookstitle.Text+"', books_image='"+path1.ToString()+"', books_author_name='"+authorname.Text+"'," +
                    " books_isbn='"+isbn.Text+"', available_qty='"+qty.Text+"' where id=" + id + "";
                cmd.ExecuteNonQuery();

            }

            if (f2.FileName.ToString() != "")
            {
                string books_pdf_name = f2.FileName.ToString();
                f1.SaveAs(Request.PhysicalApplicationPath + "/librarian/books_pdf/" + books_pdf_name.ToString());
                path2 = "books_pdf/" + books_pdf_name.ToString();

                SqlCommand cmd = con.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "update ibooks set books_title='" + bookstitle.Text + "', books_pdf='" + path2.ToString() + "', books_author_name='" + authorname.Text + "'," +
                    " books_isbn='" + isbn.Text + "', available_qty='" + qty.Text + "' where id=" + id + "";
                cmd.ExecuteNonQuery();

            }
            if (f3.FileName.ToString() != "")
            {
                string books_video_name = f3.FileName.ToString();

                f1.SaveAs(Request.PhysicalApplicationPath + "/librarian/books_video/" + books_video_name.ToString());
                path3 = "books_video/" + books_video_name.ToString();

                SqlCommand cmd = con.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "update ibooks set books_title='" + bookstitle.Text + "', books_video='" + path3.ToString() + "', books_author_name='" + authorname.Text + "'," +
                    " books_isbn='" + isbn.Text + "', available_qty='" + qty.Text + "' where id=" + id + "";
                cmd.ExecuteNonQuery();

            }

            if (f1.FileName.ToString() == "" && f2.FileName.ToString() == "" && f3.FileName.ToString() == "")
            {
                SqlCommand cmd = con.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "update ibooks set books_title='" + bookstitle.Text + "', books_author_name='" + authorname.Text + "'," +
                    " books_isbn='" + isbn.Text + "', available_qty='" + qty.Text + "' where id=" + id + "";
                cmd.ExecuteNonQuery();
            }

            Response.Redirect("display_all_books.aspx");

        }
    }
}