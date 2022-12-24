/* eslint-disable prettier/prettier */
import { UseGuards, Request, Redirect } from '@nestjs/common';
import { Controller, Get } from '@nestjs/common';
import { AuthGuard } from '@nestjs/passport';
import { AuthService } from './auth.service';

@Controller('auth')
export class AuthController {
  constructor(private authService: AuthService) { }
  @Get('github')
  @UseGuards(AuthGuard('github'))
  async githubAuth(@Request() req) {
    // The user will be redirected to GitHub to grant permission
  }

  @Get('github/callback')
  @UseGuards(AuthGuard('github'))
  @Redirect()
  async githubAuthCallback(@Request() req) {

    return this.authService.githubLogin(req);
  }

  @Get('logout')
  async logout(@Request() req) {
    console.log(req);
    req.logout();
    req.session.destroy();
  }
}