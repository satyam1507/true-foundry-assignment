/* eslint-disable prettier/prettier */
import { Octokit } from "@octokit/rest";
import { Base64 } from 'js-base64';
import * as fs from "fs";
export class AuthService {
  async githubLogin(req) {

    const octokit = new Octokit({
      auth: req.user,
    });
    // read file
    const content = fs.readFileSync("./test.cpp", "utf-8");
    const contentEncoded = Base64.encode(content);
    // create repo
    const { data } = await octokit.request('POST /user/repos', {
      name: 'Test-Repo',
      description: 'This is your test repo!',
      homepage: 'https://github.com',
      'private': true,
      is_template: false,
    })
    // add time interval to wait for repo to be created
    await new Promise((resolve) => setTimeout(resolve, 2000));
    // add file to repo
    const { data: fileData } = await octokit.request(`PUT /repos/${data.owner.login}/${data.name}/contents/test.cpp`, {
      owner: data.owner.login,
      repo: 'Test-Repo',
      path: 'test.cpp',
      message: 'Add test.cpp',
      content: contentEncoded,

    })
    // Return the url of the repo
    return {
      statusCode: 302,
      url: data.html_url,
    }
  }

}